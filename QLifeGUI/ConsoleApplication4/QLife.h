#pragma once
#include "stdafx.h"
#include "AddEvent1.h"
#include "EditEvent.h"
#include "AddToDo.h"
#include "EditToDo.h"

namespace ConsoleApplication4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for QLife
	/// </summary>
	public ref class QLife : public System::Windows::Forms::Form
	{
	public:
		QLife(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~QLife()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;


	private: System::Windows::Forms::ToolStripMenuItem^  monthToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  weekToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  monthToolStripMenuItem1;

	private: System::Windows::Forms::ToolStripMenuItem^  analysisToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fixUpToolStripMenuItem;

	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::ToolStripMenuItem^  createToDoToolStripMenuItem;




	protected:








	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint1 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
				0.25));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint2 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
				0.25));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint3 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
				0.25));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint4 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
				0.25));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->monthToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->weekToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->monthToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->analysisToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fixUpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->createToDoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->menuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(54, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"November 2016";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button2->Location = System::Drawing::Point(12, 16);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(36, 41);
			this->button2->TabIndex = 4;
			this->button2->Text = L"<";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button3->Location = System::Drawing::Point(217, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(36, 41);
			this->button3->TabIndex = 5;
			this->button3->Text = L">";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(119, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Monday";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(204, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Tuesday";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(493, 106);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 20);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Friday";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(390, 106);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 20);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Thursday";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label6->Location = System::Drawing::Point(289, 107);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(93, 20);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Wednesday";
			this->label6->Click += gcnew System::EventHandler(this, &QLife::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label7->Location = System::Drawing::Point(25, 106);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(63, 20);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Sunday";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label8->Location = System::Drawing::Point(574, 106);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(73, 20);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Saturday";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label9->Location = System::Drawing::Point(691, 305);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(106, 20);
			this->label9->TabIndex = 13;
			this->label9->Text = L"To-Do Events";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label10->Location = System::Drawing::Point(804, 305);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(96, 20);
			this->label10->TabIndex = 14;
			this->label10->Text = L"Notifications";
			this->label10->Click += gcnew System::EventHandler(this, &QLife::label10_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::OutsetDouble;
			this->tableLayoutPanel1->ColumnCount = 8;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				48)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				85)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				83)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				96)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				82)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				76)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				80)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				94)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 140);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 105)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 87)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(647, 419);
			this->tableLayoutPanel1->TabIndex = 17;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &QLife::tableLayoutPanel1_Paint);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5));
			legend1->IsTextAutoFit = false;
			legend1->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Row;
			legend1->Name = L"Legend1";
			legend1->Position->Auto = false;
			legend1->Position->Height = 8;
			legend1->Position->Width = 90.10368F;
			legend1->Position->X = 1;
			legend1->Position->Y = 92;
			legend1->TableStyle = System::Windows::Forms::DataVisualization::Charting::LegendTableStyle::Wide;
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(672, 0);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			dataPoint1->Label = L"Study";
			dataPoint2->Label = L"Social";
			dataPoint3->Label = L"Exercise";
			dataPoint4->Label = L"Sleep";
			series1->Points->Add(dataPoint1);
			series1->Points->Add(dataPoint2);
			series1->Points->Add(dataPoint3);
			series1->Points->Add(dataPoint4);
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(243, 282);
			this->chart1->TabIndex = 20;
			this->chart1->Text = L"chart1";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Location = System::Drawing::Point(561, 52);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(48, 41);
			this->button1->TabIndex = 21;
			this->button1->Text = L"+";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &QLife::button1_Click);
			// 
			// monthToolStripMenuItem
			// 
			this->monthToolStripMenuItem->Name = L"monthToolStripMenuItem";
			this->monthToolStripMenuItem->Size = System::Drawing::Size(86, 4);
			// 
			// weekToolStripMenuItem
			// 
			this->weekToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->weekToolStripMenuItem->Margin = System::Windows::Forms::Padding(0, 20, 0, 20);
			this->weekToolStripMenuItem->Name = L"weekToolStripMenuItem";
			this->weekToolStripMenuItem->Size = System::Drawing::Size(86, 28);
			this->weekToolStripMenuItem->Text = L"Week";
			this->weekToolStripMenuItem->Click += gcnew System::EventHandler(this, &QLife::weekToolStripMenuItem_Click);
			// 
			// monthToolStripMenuItem1
			// 
			this->monthToolStripMenuItem1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->monthToolStripMenuItem1->Margin = System::Windows::Forms::Padding(0, 20, 0, 20);
			this->monthToolStripMenuItem1->Name = L"monthToolStripMenuItem1";
			this->monthToolStripMenuItem1->Size = System::Drawing::Size(86, 28);
			this->monthToolStripMenuItem1->Text = L"Month";
			this->monthToolStripMenuItem1->Click += gcnew System::EventHandler(this, &QLife::monthToolStripMenuItem1_Click);
			// 
			// analysisToolStripMenuItem
			// 
			this->analysisToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->analysisToolStripMenuItem->Margin = System::Windows::Forms::Padding(0, 20, 0, 20);
			this->analysisToolStripMenuItem->Name = L"analysisToolStripMenuItem";
			this->analysisToolStripMenuItem->Size = System::Drawing::Size(86, 22);
			this->analysisToolStripMenuItem->Text = L"Analysis";
			this->analysisToolStripMenuItem->Click += gcnew System::EventHandler(this, &QLife::analysisToolStripMenuItem_Click);
			// 
			// fixUpToolStripMenuItem
			// 
			this->fixUpToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->fixUpToolStripMenuItem->Margin = System::Windows::Forms::Padding(0, 20, 0, 20);
			this->fixUpToolStripMenuItem->Name = L"fixUpToolStripMenuItem";
			this->fixUpToolStripMenuItem->Size = System::Drawing::Size(86, 28);
			this->fixUpToolStripMenuItem->Text = L"Fix Up";
			this->fixUpToolStripMenuItem->Click += gcnew System::EventHandler(this, &QLife::fixUpToolStripMenuItem_Click);
			// 
			// menuStrip2
			// 
			this->menuStrip2->Dock = System::Windows::Forms::DockStyle::Right;
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->monthToolStripMenuItem,
					this->weekToolStripMenuItem, this->monthToolStripMenuItem1, this->analysisToolStripMenuItem, this->fixUpToolStripMenuItem, this->createToDoToolStripMenuItem
			});
			this->menuStrip2->Location = System::Drawing::Point(928, 0);
			this->menuStrip2->Margin = System::Windows::Forms::Padding(0, 10, 0, 10);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Padding = System::Windows::Forms::Padding(5, 4, 0, 4);
			this->menuStrip2->Size = System::Drawing::Size(97, 632);
			this->menuStrip2->TabIndex = 1;
			this->menuStrip2->Text = L"menuStrip2";
			this->menuStrip2->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &QLife::menuStrip2_ItemClicked);
			// 
			// createToDoToolStripMenuItem
			// 
			this->createToDoToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->createToDoToolStripMenuItem->Margin = System::Windows::Forms::Padding(0, 20, 0, 20);
			this->createToDoToolStripMenuItem->Name = L"createToDoToolStripMenuItem";
			this->createToDoToolStripMenuItem->Size = System::Drawing::Size(86, 26);
			this->createToDoToolStripMenuItem->Text = L"+ To-Do";
			this->createToDoToolStripMenuItem->Click += gcnew System::EventHandler(this, &QLife::createToDoToolStripMenuItem_Click);
			// 
			// label11
			// 
			this->label11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label11->Location = System::Drawing::Point(689, 334);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(108, 254);
			this->label11->TabIndex = 22;
			this->label11->Text = L"        ";
			this->label11->Click += gcnew System::EventHandler(this, &QLife::label11_Click);
			// 
			// label12
			// 
			this->label12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label12->Location = System::Drawing::Point(808, 334);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(107, 254);
			this->label12->TabIndex = 23;
			this->label12->Text = L" ";
			this->label12->Click += gcnew System::EventHandler(this, &QLife::label12_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel2->ColumnCount = 7;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				14.28571F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				14.28571F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				14.28571F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				14.28571F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				14.28571F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				14.28571F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				14.28571F)));
			this->tableLayoutPanel2->Location = System::Drawing::Point(12, 140);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 24;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.166668F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(647, 469);
			this->tableLayoutPanel2->TabIndex = 24;
			// 
			// QLife
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSkyBlue;
			this->ClientSize = System::Drawing::Size(1025, 632);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip2);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"QLife";
			this->Text = L"QLife";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Settings_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void settingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label10_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void richTextBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
	private: System::Void menuStrip2_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		AddEvent1 ^ addevent = gcnew AddEvent1();
		addevent->Show();

	}
	private: System::Void analysisToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		
			
		this->chart1->Series->Clear();
		System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint1 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
			0.20));
		System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint2 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
			0.20));
		System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint3 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
			0.10));
		System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint4 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
			0.5));
		System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
		series1->ChartArea = L"ChartArea1";
		series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
		series1->Legend = L"Legend1";
		series1->Name = L"Series1";
		dataPoint1->Label = L"Study";
		dataPoint2->Label = L"Social";
		dataPoint3->Label = L"Exercise";
		dataPoint4->Label = L"Sleep";
		series1->Points->Add(dataPoint1);
		series1->Points->Add(dataPoint2);
		series1->Points->Add(dataPoint3);
		series1->Points->Add(dataPoint4);
		this->chart1->Series->Add(series1);
		

	};
	private: System::Void label11_Click(System::Object^  sender, System::EventArgs^  e) {
		/*if(To-dos.amount=0){
		label11->Text = "You should do something!"
		}
		*/
	}
	private: System::Void label12_Click(System::Object^  sender, System::EventArgs^  e) {
		/*if(No upcoming events){
		label12->Text = "Nothing coming up, enjoy yourself!"
		}
		*/
	}
	private: System::Void monthToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		tableLayoutPanel2->Hide();
		tableLayoutPanel1->Show();
	}
	private: System::Void weekToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		tableLayoutPanel1->Hide();
		tableLayoutPanel2->Show();
	}

	private: System::Void createToDoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		AddToDo ^ addtodo = gcnew AddToDo();
		addtodo->Show();
	}
	private: System::Void fixUpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		tableLayoutPanel2->Controls->Clear();
		Button^ myButton = gcnew Button();
		myButton->BackColor = System::Drawing::SystemColors::ActiveCaption;
		myButton->Dock = DockStyle::Fill;
		myButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
		myButton->ForeColor = Color::Wheat;
		myButton->Click += gcnew System::EventHandler(this, &QLife::myButton_Click);
		myButton->Text = "CMPE 320";
		myButton->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
		tableLayoutPanel2->Controls->Add(myButton);
		tableLayoutPanel2->SetCellPosition(myButton, TableLayoutPanelCellPosition(5, 3));
		tableLayoutPanel2->SetRowSpan(myButton, 2);
	}
	private: System::Void myButton_Click(System::Object^  sender, System::EventArgs^  e) {
		EditEvent ^ editevent = gcnew EditEvent();
		editevent->Show();
	}
	}
	;
}