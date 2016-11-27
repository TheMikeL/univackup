# 1  day     = 86400 seconds
# 60 minutes = 3600  seconds
# 30 minutes = 1800  seconds
# 15 minutes = 900   seconds
import random
import datetime

# Returns the number of seconds that corresponds to the next
# periodSize. Eg. 7:43:32 -> 8:00:00 if period size is 30 minutes,
# and 7:43:32 -> 7:45:00 if period size is 15 minutes
def nextPeriod(seconds, periodSize):
    diff = seconds % periodSize
    if diff == 0:
        return seconds
    else:
        return seconds + (periodSize - diff)

# Pair with nextPeriod. Returns the number of seconds that corresponds to
# the previous periodSize. Eg. 7:47:32 -> 7:45:00 if period size is 15 minutes,
# and 7:47:32 -> 7:30:00 if period size is 30 minutes
def lastPeriod(seconds, periodSize):
    return seconds - (seconds % periodSize)

# Demonstrating how to turn a datetime into a better datetime for calendars
def normalizeTimes():
    # First we generate a list of 10 times up to 1 day apart
    times = [random.randint(100000, 186400) for x in range(0, 10)]
    print("Initial Times\n" + str(times))
    # Then we sort...
    times.sort()
    print("Sorted Times\n" + str(times))
    # And adjust to fit in 30 minute offsets
    times = [nextPeriod(x, 1800) for x in times]
    print("Adjusted Times (30 minutes)\n" + str(times))
    dates = [datetime.datetime.fromtimestamp(x) for x in times]
    print("Day:Hour:Minute:Second\n" + str([str(x.day) + ':' + str(x.hour) + ':' + str(x.minute) + ':' + str(x.second) for x in dates]))

normalizeTimes()
# Take a sorted list of start and end times (representing events) and return an array
# of '0' for free(, or 'X' for the highest weight in that spot.) - maybe to do later, would
# require an extra order of complexity if events overlapped
# times[0] is start time of event
# times[1] is end time of event
def freeTime(start, end, times, periodSize):
    current = nextPeriod(start, periodSize)
    result = []
    index = 0
    print(times)
    while current < lastPeriod(end, periodSize):
        # We can't have any more conflicts if this is true
        if index >= len(times):
            break
        # We need to increase the index of our sorted events list to check for conflicts
        elif current >= nextPeriod(times[index][1], periodSize):
            index += 1
        # This means an event is in the spot
        elif current >= lastPeriod(times[index][0], periodSize) and current < nextPeriod(times[index][1], periodSize):
            #print("c:", current, "start:", lastPeriod(times[index][0], periodSize), "end:", nextPeriod(times[index][1], periodSize), "busy!")
            result.append(1) # busy
            current += periodSize
        else:
            #print("c:", current, "start:", lastPeriod(times[index][0], periodSize), "end:", nextPeriod(times[index][1], periodSize), "free!")
            result.append(0) # free
            current += periodSize
    # Finish up any leftover conflict-free time
    while current < lastPeriod(end, periodSize):
        #print("c:", current, "trivially free!")
        current += periodSize
        result.append(0)
    return result

x = [(13, 17), (50, 70), (110, 120), (167, 208), (250, 301)]
print("Free time:", freeTime(0, 350, x, 15))

# Takes events and converts and sequential or overlapping events into a single 'blocked time' event
def combineIntervals(times, periodSize):
    # Simple rule: if second time's start is before first time's end there is intersection
    result = [(lastPeriod(times[0][0], periodSize), nextPeriod(times[0][1], periodSize))]
    for i in range(1, len(times)):
        if nextPeriod(times[i-1][1], periodSize) >= lastPeriod(times[i][0], periodSize):
            result[-1] = (result[-1][0], max(nextPeriod(times[i-1][1], periodSize), nextPeriod(times[i][1], periodSize)))
        else:
            result.append((lastPeriod(times[i][0], periodSize), nextPeriod(times[i][1], periodSize)))
    return result

y = [(1, 8), (4, 5), (10, 15), (13, 17), (20, 21)]
print("Combine intervals:", combineIntervals(y, 1))
print("Combine intervals:", combineIntervals(y, 5))

# Instead of going through every spot in a boolean array, we can combine intervals together and make accurate free-time information that is
# versatile
def betterFreeTime(start, end, times, periodSize):
    # First combine all events
    times = combineIntervals(times, periodSize)
    freeTime = []
    cTime = start # current time
    index = 0 # index of times
    while cTime < end and index < len(times):
        if cTime < times[index][0]:
            freeTime.append((cTime, times[index][0]))
        cTime = times[index][1]
        index += 1
    if index == len(times):
        freeTime.append((cTime, end))
    return freeTime

x = [(13, 60), (50, 70), (110, 120), (167, 208), (200, 301)]

print("Better free time:", betterFreeTime(15, 500, x, 15))


