#pragma once

namespace ConsoleApplication4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditEvent
	/// </summary>
	public ref class EditEvent : public System::Windows::Forms::Form
	{
	public:
		EditEvent(void)
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
		~EditEvent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox3;
	protected:
	private: System::Windows::Forms::ComboBox^  comboBox7;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::ComboBox^  comboBox6;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

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
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox7 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(153, 48);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(165, 20);
			this->textBox3->TabIndex = 33;
			// 
			// comboBox7
			// 
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Test", L"Assignment", L"Social", L"Exercise",
					L"Other"
			});
			this->comboBox7->Location = System::Drawing::Point(153, 99);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(121, 21);
			this->comboBox7->TabIndex = 32;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(153, 153);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(165, 83);
			this->textBox2->TabIndex = 31;
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"AM", L"PM" });
			this->comboBox4->Location = System::Drawing::Point(272, 255);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(46, 21);
			this->comboBox4->TabIndex = 30;
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(13) {
				L"00", L"05", L"10", L"15", L"20", L"25", L"30",
					L"35", L"40", L"45", L"50", L"55", L"60"
			});
			this->comboBox5->Location = System::Drawing::Point(212, 254);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(36, 21);
			this->comboBox5->TabIndex = 29;
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12"
			});
			this->comboBox6->Location = System::Drawing::Point(153, 255);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(38, 21);
			this->comboBox6->TabIndex = 28;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"AM", L"PM" });
			this->comboBox3->Location = System::Drawing::Point(272, 309);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(46, 21);
			this->comboBox3->TabIndex = 27;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(13) {
				L"00", L"05", L"10", L"15", L"20", L"25", L"30",
					L"35", L"40", L"45", L"50", L"55", L"60"
			});
			this->comboBox2->Location = System::Drawing::Point(212, 307);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(36, 21);
			this->comboBox2->TabIndex = 26;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12"
			});
			this->comboBox1->Location = System::Drawing::Point(153, 309);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(38, 21);
			this->comboBox1->TabIndex = 25;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(153, 370);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 24;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button1->Location = System::Drawing::Point(81, 415);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 33);
			this->button1->TabIndex = 23;
			this->button1->Text = L"Change Event";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label6->Location = System::Drawing::Point(28, 370);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 20);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Weight";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(28, 307);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 20);
			this->label5->TabIndex = 21;
			this->label5->Text = L"End Time";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(28, 255);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 20);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Start Time";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(28, 153);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 20);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Ðescription";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(28, 101);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 20);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Event Type";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(28, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 20);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Title";
			// 
			// EditEvent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(350, 477);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->comboBox7);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"EditEvent";
			this->Text = L"EditEvent";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
