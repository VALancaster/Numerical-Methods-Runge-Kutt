#pragma once
#include <math.h>

namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			SetupTable();
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->MinimumSize = System::Drawing::Size(1280, 720);
			zedGraphControl1->IsEnableWheelZoom = true; // разрешен зум колесиком мыши
			// разрешено выделение рамкой для зума
			zedGraphControl1->IsEnableHZoom = true;
			zedGraphControl1->IsEnableVZoom = true;
			// разрешено перетаскивание графика 
			zedGraphControl1->IsEnableHPan = true;
			zedGraphControl1->IsEnableVPan = true;
			// сброс масштаба при двойном клике
			zedGraphControl1->IsShowContextMenu = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ZedGraph::ZedGraphControl^ zedGraphControl1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ X;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ F_1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ F_2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;









	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		// Данные для графиков
		PointPairList^ list_u = gcnew PointPairList(); // график смещения u(x)
		PointPairList^ list_v = gcnew PointPairList(); // график скорости u'(x)
		PointPairList^ list_exact = gcnew PointPairList(); // график точного решения (для тестовой задачи)
	private: System::Windows::Forms::RadioButton^ radioTest;
	private: System::Windows::Forms::RadioButton^ radioMain;

	private: System::Windows::Forms::TextBox^ textBoxN;




	private: System::Windows::Forms::TextBox^ textBoxEps;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::CheckBox^ checkAdaptive;
	private: System::Windows::Forms::TextBox^ textBoxEpsB;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnReset;
	private: System::Windows::Forms::TextBox^ textBoxU0;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label9;

	private: System::Windows::Forms::TextBox^ txtM;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ txtKS;

	private: System::Windows::Forms::TextBox^ txtK;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txtC;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ txtNmax;
	private: System::Windows::Forms::TextBox^ txtV0;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::RadioButton^ rbPhase;
	private: System::Windows::Forms::RadioButton^ rbV;
	private: System::Windows::Forms::RadioButton^ rbU;



		   PointPairList^ list_phase = gcnew PointPairList(); // фазовый портрет

		   // Настройка колонок таблицы
		   void SetupTable() {
			   dataGridView1->Columns->Clear();
			   dataGridView1->Columns->Add("i", "i");
			   dataGridView1->Columns->Add("xi", "xi");
			   dataGridView1->Columns->Add("vi", "vi");
			   dataGridView1->Columns->Add("v2i", "v2i");
			   dataGridView1->Columns->Add("diff", "vi-v2i");
			   dataGridView1->Columns->Add("olp", "OLP");
			   dataGridView1->Columns->Add("hi", "hi");
			   dataGridView1->Columns->Add("c1", "c1");
			   dataGridView1->Columns->Add("c2", "c2");

			   if (radioTest->Checked) {
				   dataGridView1->Columns->Add("ui", "ui (точное)");
				   dataGridView1->Columns->Add("err", "|ui - vi|");
			   }

			   // Формат вывода (обычная десятичная дробь)
			   dataGridView1->Columns[1]->DefaultCellStyle->Format = "F10"; // xi
			   dataGridView1->Columns[2]->DefaultCellStyle->Format = "F10"; // vi
			   dataGridView1->Columns[3]->DefaultCellStyle->Format = "F10"; // v2i
			   dataGridView1->Columns[4]->DefaultCellStyle->Format = "F10"; // vi-v2i
			   dataGridView1->Columns[5]->DefaultCellStyle->Format = "F10"; // OLP
			   dataGridView1->Columns[6]->DefaultCellStyle->Format = "F10"; // hi

			   if (radioTest->Checked) {
				   dataGridView1->Columns[9]->DefaultCellStyle->Format = "F10"; // ui
				   dataGridView1->Columns[10]->DefaultCellStyle->Format = "F10"; // |ui-vi|
			   }
		   }


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->F_1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->F_2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->radioTest = (gcnew System::Windows::Forms::RadioButton());
			   this->radioMain = (gcnew System::Windows::Forms::RadioButton());
			   this->textBoxN = (gcnew System::Windows::Forms::TextBox());
			   this->textBoxEps = (gcnew System::Windows::Forms::TextBox());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->rbPhase = (gcnew System::Windows::Forms::RadioButton());
			   this->rbV = (gcnew System::Windows::Forms::RadioButton());
			   this->rbU = (gcnew System::Windows::Forms::RadioButton());
			   this->label14 = (gcnew System::Windows::Forms::Label());
			   this->txtNmax = (gcnew System::Windows::Forms::TextBox());
			   this->txtV0 = (gcnew System::Windows::Forms::TextBox());
			   this->label13 = (gcnew System::Windows::Forms::Label());
			   this->label12 = (gcnew System::Windows::Forms::Label());
			   this->txtKS = (gcnew System::Windows::Forms::TextBox());
			   this->txtK = (gcnew System::Windows::Forms::TextBox());
			   this->label11 = (gcnew System::Windows::Forms::Label());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   this->txtC = (gcnew System::Windows::Forms::TextBox());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->txtM = (gcnew System::Windows::Forms::TextBox());
			   this->textBoxU0 = (gcnew System::Windows::Forms::TextBox());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->btnReset = (gcnew System::Windows::Forms::Button());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->textBoxEpsB = (gcnew System::Windows::Forms::TextBox());
			   this->checkAdaptive = (gcnew System::Windows::Forms::CheckBox());
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->panel1->SuspendLayout();
			   this->tableLayoutPanel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // zedGraphControl1
			   // 
			   this->zedGraphControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->zedGraphControl1->Location = System::Drawing::Point(3, 3);
			   this->zedGraphControl1->Name = L"zedGraphControl1";
			   this->zedGraphControl1->ScrollGrace = 0;
			   this->zedGraphControl1->ScrollMaxX = 0;
			   this->zedGraphControl1->ScrollMaxY = 0;
			   this->zedGraphControl1->ScrollMaxY2 = 0;
			   this->zedGraphControl1->ScrollMinX = 0;
			   this->zedGraphControl1->ScrollMinY = 0;
			   this->zedGraphControl1->ScrollMinY2 = 0;
			   this->zedGraphControl1->Size = System::Drawing::Size(689, 310);
			   this->zedGraphControl1->TabIndex = 0;
			   this->zedGraphControl1->Load += gcnew System::EventHandler(this, &MyForm::zedGraphControl1_Load);
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(1108, 15);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(182, 65);
			   this->button1->TabIndex = 1;
			   this->button1->Text = L"Draw";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				   this->X, this->F_1,
					   this->F_2
			   });
			   this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->dataGridView1->Location = System::Drawing::Point(698, 3);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersVisible = false;
			   this->dataGridView1->Size = System::Drawing::Size(689, 310);
			   this->dataGridView1->TabIndex = 2;
			   this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			   // 
			   // X
			   // 
			   this->X->HeaderText = L"X";
			   this->X->Name = L"X";
			   this->X->ReadOnly = true;
			   // 
			   // F_1
			   // 
			   this->F_1->HeaderText = L"F_1";
			   this->F_1->Name = L"F_1";
			   this->F_1->ReadOnly = true;
			   // 
			   // F_2
			   // 
			   this->F_2->HeaderText = L"F_2";
			   this->F_2->Name = L"F_2";
			   this->F_2->ReadOnly = true;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(43, 22);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(13, 13);
			   this->label1->TabIndex = 3;
			   this->label1->Text = L"a";
			   this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(62, 19);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(48, 20);
			   this->textBox1->TabIndex = 4;
			   this->textBox1->Text = L"0";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(43, 66);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(13, 13);
			   this->label2->TabIndex = 5;
			   this->label2->Text = L"b";
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(62, 63);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(49, 20);
			   this->textBox2->TabIndex = 6;
			   this->textBox2->Text = L"1";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(43, 116);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(13, 13);
			   this->label3->TabIndex = 7;
			   this->label3->Text = L"h";
			   // 
			   // textBox3
			   // 
			   this->textBox3->Location = System::Drawing::Point(62, 109);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(48, 20);
			   this->textBox3->TabIndex = 8;
			   this->textBox3->Text = L"0,0001";
			   this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			   // 
			   // radioTest
			   // 
			   this->radioTest->AutoSize = true;
			   this->radioTest->Location = System::Drawing::Point(911, 18);
			   this->radioTest->Name = L"radioTest";
			   this->radioTest->Size = System::Drawing::Size(111, 17);
			   this->radioTest->TabIndex = 14;
			   this->radioTest->Text = L"Тестовая задача";
			   this->radioTest->UseVisualStyleBackColor = true;
			   this->radioTest->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			   // 
			   // radioMain
			   // 
			   this->radioMain->AutoSize = true;
			   this->radioMain->Location = System::Drawing::Point(911, 53);
			   this->radioMain->Name = L"radioMain";
			   this->radioMain->Size = System::Drawing::Size(113, 17);
			   this->radioMain->TabIndex = 15;
			   this->radioMain->Text = L"Основная задача";
			   this->radioMain->UseVisualStyleBackColor = true;
			   // 
			   // textBoxN
			   // 
			   this->textBoxN->Location = System::Drawing::Point(592, 86);
			   this->textBoxN->Name = L"textBoxN";
			   this->textBoxN->Size = System::Drawing::Size(100, 20);
			   this->textBoxN->TabIndex = 17;
			   this->textBoxN->Text = L"11";
			   this->textBoxN->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxN_TextChanged);
			   // 
			   // textBoxEps
			   // 
			   this->textBoxEps->Location = System::Drawing::Point(592, 15);
			   this->textBoxEps->Name = L"textBoxEps";
			   this->textBoxEps->Size = System::Drawing::Size(100, 20);
			   this->textBoxEps->TabIndex = 18;
			   this->textBoxEps->Text = L"0,00001";
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(343, 22);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(132, 13);
			   this->label6->TabIndex = 19;
			   this->label6->Text = L"Локальная погрешность";
			   this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Location = System::Drawing::Point(343, 86);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(49, 13);
			   this->label7->TabIndex = 20;
			   this->label7->Text = L"Вариант";
			   // 
			   // panel1
			   // 
			   this->panel1->Controls->Add(this->rbPhase);
			   this->panel1->Controls->Add(this->rbV);
			   this->panel1->Controls->Add(this->rbU);
			   this->panel1->Controls->Add(this->label14);
			   this->panel1->Controls->Add(this->txtNmax);
			   this->panel1->Controls->Add(this->txtV0);
			   this->panel1->Controls->Add(this->label13);
			   this->panel1->Controls->Add(this->label12);
			   this->panel1->Controls->Add(this->txtKS);
			   this->panel1->Controls->Add(this->txtK);
			   this->panel1->Controls->Add(this->label11);
			   this->panel1->Controls->Add(this->label10);
			   this->panel1->Controls->Add(this->txtC);
			   this->panel1->Controls->Add(this->label9);
			   this->panel1->Controls->Add(this->txtM);
			   this->panel1->Controls->Add(this->textBoxU0);
			   this->panel1->Controls->Add(this->label5);
			   this->panel1->Controls->Add(this->btnReset);
			   this->panel1->Controls->Add(this->label4);
			   this->panel1->Controls->Add(this->textBoxEpsB);
			   this->panel1->Controls->Add(this->checkAdaptive);
			   this->panel1->Controls->Add(this->label3);
			   this->panel1->Controls->Add(this->textBox3);
			   this->panel1->Controls->Add(this->textBox2);
			   this->panel1->Controls->Add(this->label6);
			   this->panel1->Controls->Add(this->label2);
			   this->panel1->Controls->Add(this->label7);
			   this->panel1->Controls->Add(this->textBox1);
			   this->panel1->Controls->Add(this->textBoxEps);
			   this->panel1->Controls->Add(this->label1);
			   this->panel1->Controls->Add(this->radioTest);
			   this->panel1->Controls->Add(this->radioMain);
			   this->panel1->Controls->Add(this->textBoxN);
			   this->panel1->Controls->Add(this->button1);
			   this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->panel1->Location = System::Drawing::Point(0, 316);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(1390, 236);
			   this->panel1->TabIndex = 21;
			   // 
			   // rbPhase
			   // 
			   this->rbPhase->AutoSize = true;
			   this->rbPhase->Location = System::Drawing::Point(739, 82);
			   this->rbPhase->Name = L"rbPhase";
			   this->rbPhase->Size = System::Drawing::Size(117, 17);
			   this->rbPhase->TabIndex = 43;
			   this->rbPhase->Text = L"Фазовый портрет";
			   this->rbPhase->UseVisualStyleBackColor = true;
			   this->rbPhase->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbPhase_CheckedChanged);
			   // 
			   // rbV
			   // 
			   this->rbV->AutoSize = true;
			   this->rbV->Location = System::Drawing::Point(739, 47);
			   this->rbV->Name = L"rbV";
			   this->rbV->Size = System::Drawing::Size(97, 17);
			   this->rbV->TabIndex = 42;
			   this->rbV->Text = L"Скорость U\'(x)";
			   this->rbV->UseVisualStyleBackColor = true;
			   this->rbV->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbV_CheckedChanged);
			   // 
			   // rbU
			   // 
			   this->rbU->AutoSize = true;
			   this->rbU->Checked = true;
			   this->rbU->Location = System::Drawing::Point(739, 15);
			   this->rbU->Name = L"rbU";
			   this->rbU->Size = System::Drawing::Size(104, 17);
			   this->rbU->TabIndex = 41;
			   this->rbU->TabStop = true;
			   this->rbU->Text = L"Смещение U(x) ";
			   this->rbU->UseVisualStyleBackColor = true;
			   this->rbU->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbU_CheckedChanged);
			   // 
			   // label14
			   // 
			   this->label14->AutoSize = true;
			   this->label14->Location = System::Drawing::Point(127, 109);
			   this->label14->Name = L"label14";
			   this->label14->Size = System::Drawing::Size(34, 13);
			   this->label14->TabIndex = 40;
			   this->label14->Text = L"Nmax";
			   // 
			   // txtNmax
			   // 
			   this->txtNmax->Location = System::Drawing::Point(174, 109);
			   this->txtNmax->Name = L"txtNmax";
			   this->txtNmax->Size = System::Drawing::Size(80, 20);
			   this->txtNmax->TabIndex = 39;
			   this->txtNmax->Text = L"1000";
			   // 
			   // txtV0
			   // 
			   this->txtV0->Location = System::Drawing::Point(172, 60);
			   this->txtV0->Name = L"txtV0";
			   this->txtV0->Size = System::Drawing::Size(82, 20);
			   this->txtV0->TabIndex = 38;
			   this->txtV0->Text = L"0";
			   // 
			   // label13
			   // 
			   this->label13->AutoSize = true;
			   this->label13->Location = System::Drawing::Point(145, 63);
			   this->label13->Name = L"label13";
			   this->label13->Size = System::Drawing::Size(21, 13);
			   this->label13->TabIndex = 37;
			   this->label13->Text = L"u\'0";
			   // 
			   // label12
			   // 
			   this->label12->AutoSize = true;
			   this->label12->Location = System::Drawing::Point(151, 207);
			   this->label12->Name = L"label12";
			   this->label12->Size = System::Drawing::Size(17, 13);
			   this->label12->TabIndex = 36;
			   this->label12->Text = L"k*";
			   // 
			   // txtKS
			   // 
			   this->txtKS->Location = System::Drawing::Point(172, 200);
			   this->txtKS->Name = L"txtKS";
			   this->txtKS->Size = System::Drawing::Size(69, 20);
			   this->txtKS->TabIndex = 35;
			   this->txtKS->Text = L"2,0";
			   // 
			   // txtK
			   // 
			   this->txtK->Location = System::Drawing::Point(172, 175);
			   this->txtK->Name = L"txtK";
			   this->txtK->Size = System::Drawing::Size(69, 20);
			   this->txtK->TabIndex = 34;
			   this->txtK->Text = L"2,0";
			   // 
			   // label11
			   // 
			   this->label11->AutoSize = true;
			   this->label11->Location = System::Drawing::Point(155, 178);
			   this->label11->Name = L"label11";
			   this->label11->Size = System::Drawing::Size(13, 13);
			   this->label11->TabIndex = 32;
			   this->label11->Text = L"k";
			   // 
			   // label10
			   // 
			   this->label10->AutoSize = true;
			   this->label10->Location = System::Drawing::Point(41, 207);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(13, 13);
			   this->label10->TabIndex = 31;
			   this->label10->Text = L"c";
			   // 
			   // txtC
			   // 
			   this->txtC->Location = System::Drawing::Point(62, 200);
			   this->txtC->Name = L"txtC";
			   this->txtC->Size = System::Drawing::Size(69, 20);
			   this->txtC->TabIndex = 30;
			   this->txtC->Text = L"0,15";
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Location = System::Drawing::Point(41, 178);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(15, 13);
			   this->label9->TabIndex = 29;
			   this->label9->Text = L"m";
			   // 
			   // txtM
			   // 
			   this->txtM->Location = System::Drawing::Point(62, 175);
			   this->txtM->Name = L"txtM";
			   this->txtM->Size = System::Drawing::Size(69, 20);
			   this->txtM->TabIndex = 27;
			   this->txtM->Text = L"0,01";
			   // 
			   // textBoxU0
			   // 
			   this->textBoxU0->Location = System::Drawing::Point(174, 19);
			   this->textBoxU0->Name = L"textBoxU0";
			   this->textBoxU0->Size = System::Drawing::Size(80, 20);
			   this->textBoxU0->TabIndex = 26;
			   this->textBoxU0->Text = L"10";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(149, 23);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(19, 13);
			   this->label5->TabIndex = 25;
			   this->label5->Text = L"u0";
			   this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			   // 
			   // btnReset
			   // 
			   this->btnReset->Location = System::Drawing::Point(1108, 124);
			   this->btnReset->Name = L"btnReset";
			   this->btnReset->Size = System::Drawing::Size(182, 67);
			   this->btnReset->TabIndex = 24;
			   this->btnReset->Text = L"Reset";
			   this->btnReset->UseVisualStyleBackColor = true;
			   this->btnReset->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(343, 51);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(213, 13);
			   this->label4->TabIndex = 23;
			   this->label4->Text = L"Погрешность выхода за правую границу";
			   // 
			   // textBoxEpsB
			   // 
			   this->textBoxEpsB->Location = System::Drawing::Point(592, 48);
			   this->textBoxEpsB->Name = L"textBoxEpsB";
			   this->textBoxEpsB->Size = System::Drawing::Size(100, 20);
			   this->textBoxEpsB->TabIndex = 22;
			   this->textBoxEpsB->Text = L"0,0001";
			   // 
			   // checkAdaptive
			   // 
			   this->checkAdaptive->AutoSize = true;
			   this->checkAdaptive->Checked = true;
			   this->checkAdaptive->CheckState = System::Windows::Forms::CheckState::Checked;
			   this->checkAdaptive->Location = System::Drawing::Point(911, 89);
			   this->checkAdaptive->Name = L"checkAdaptive";
			   this->checkAdaptive->Size = System::Drawing::Size(110, 17);
			   this->checkAdaptive->TabIndex = 21;
			   this->checkAdaptive->Text = L"Адаптивный шаг";
			   this->checkAdaptive->UseVisualStyleBackColor = true;
			   this->checkAdaptive->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			   // 
			   // tableLayoutPanel1
			   // 
			   this->tableLayoutPanel1->ColumnCount = 2;
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   50)));
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   50)));
			   this->tableLayoutPanel1->Controls->Add(this->dataGridView1, 1, 0);
			   this->tableLayoutPanel1->Controls->Add(this->zedGraphControl1, 0, 0);
			   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 1;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(1390, 316);
			   this->tableLayoutPanel1->TabIndex = 22;
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1390, 552);
			   this->Controls->Add(this->tableLayoutPanel1);
			   this->Controls->Add(this->panel1);
			   this->Name = L"MyForm";
			   this->Text = L"MyForm";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->tableLayoutPanel1->ResumeLayout(false);
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private:
		double m_val;
		double k_val;
		double ks_val;
		double c_val;

		double f1(double x) {
			return sin(x);
		}

		double f2(double x) {
			return sin(2 * x);
		}

		void GetDerivs(double x, double u, double v, double& du, double& dv) {
			if (radioTest->Checked) { // тестовая задача
				int N = Convert::ToInt32(textBoxN->Text);
				du = Math::Pow(-1.0, N) * (N / 2.0) * u;
				dv = 0.0;
			}
			else { // основная задача
				du = v;
				dv = -(c_val * v + k_val * u + ks_val * Math::Pow(u, 3)) / m_val;
			}
		}

		// шаг Рунге-Кутта 4 порядка
		void RK4_Step(double x, double u, double v, double h, double& u_next, double& v_next) {
			double k1u, k1v, k2u, k2v, k3u, k3v, k4u, k4v;

			GetDerivs(x, u, v, k1u, k1v);
			GetDerivs(x + h / 2.0, u + h * k1u / 2.0, v + h * k1v / 2.0, k2u, k2v);
			GetDerivs(x + h / 2.0, u + h * k2u / 2.0, v + h * k2v / 2.0, k3u, k3v);
			GetDerivs(x + h, u + h * k3u, v + h * k3v, k4u, k4v);

			u_next = u + (h / 6.0) * (k1u + 2.0 * k2u + 2.0 * k3u + k4u);
			v_next = v + (h / 6.0) * (k1v + 2.0 * k2v + 2.0 * k3v + k4v);
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try {

			SetupTable();

			// Считывание параметров из формы
			m_val = Convert::ToDouble(txtM->Text->Replace(".", ",")); // m
			c_val = Convert::ToDouble(txtC->Text->Replace(".", ",")); // c
			k_val = Convert::ToDouble(txtK->Text->Replace(".", ",")); // k
			ks_val = Convert::ToDouble(txtKS->Text->Replace(".", ",")); // k*

			double u0 = Convert::ToDouble(textBoxU0->Text->Replace(".", ",")); // u0
			double v0 = 0.0; // u'0
			double h_start = Convert::ToDouble(textBox3->Text->Replace(".", ",")); // начальный шаг
			double a = Convert::ToDouble(textBox1->Text->Replace(".", ",")); // левая граница
			double b = Convert::ToDouble(textBox2->Text->Replace(".", ",")); // правая граница

			double eps_olp = Convert::ToDouble(textBoxEps->Text->Replace(".", ",")); // параметр контроля локальное погрешности
			double eps_border = Convert::ToDouble(textBoxEpsB->Text->Replace(".", ",")); // параметр контроля выхода за правую границу

			int N_var = Convert::ToInt32(textBoxN->Text);
			int N_max = Convert::ToInt32(txtNmax->Text); // максимальное количество шагов
			int i = 0;

			double x = a;
			double u = u0;
			double v = v0;
			double current_h = h_start; // временная переменная для шага

			// Статистика
			int total_divisions = 0;
			int total_doublings = 0;
			double max_olp = 0.0;
			double x_max_olp = a;
			double max_h = h_start;
			double x_max_h = a;
			double min_h = h_start;
			double x_min_h = a;
			double max_global_err = 0.0; // Для тестовой задачи: max |ui - vi|
			double x_max_err = a;

			list_u->Clear();
			list_v->Clear();
			list_phase->Clear();
			list_exact->Clear();
			dataGridView1->Rows->Clear();

			dataGridView1->Visible = false;

			bool isAdaptive = checkAdaptive->Checked;

			list_u->Add(x, u);
			list_v->Add(x, v);
			list_phase->Add(u, v);
			int r0 = dataGridView1->Rows->Add();
			dataGridView1->Rows[r0]->Cells[0]->Value = i;
			dataGridView1->Rows[r0]->Cells[1]->Value = x;
			dataGridView1->Rows[r0]->Cells[2]->Value = u;
			dataGridView1->Rows[r0]->Cells[6]->Value = 0; // Шага еще нет
			if (radioTest->Checked) {
				list_exact->Add(x, u);
				dataGridView1->Rows[r0]->Cells[9]->Value = u;
				dataGridView1->Rows[r0]->Cells[10]->Value = 0;
			}

			i++;

			int current_c1 = 0;
			int current_c2 = 0;

			// основной цикл интегрирования
			while (x < b - eps_border && i < N_max) {

				if (x + current_h > b)
					current_h = b - x;

				double u_h, v_h;
				double u_half2 = 0, v_half2 = 0;
				double olp = 0;

				RK4_Step(x, u, v, current_h, u_h, v_h);

				if (Double::IsInfinity(u_h) || Double::IsNaN(u_h)) {
					current_h /= 2.0; // резкое уменьшение шага
					total_divisions++;
					current_c1 = 1;
					if (current_h < 1e-15) {
						MessageBox::Show("Система расходится даже при минимальном шаге!");
						break;
					}
					continue;
				}

				if (isAdaptive) {
					double u_half, v_half;
					RK4_Step(x, u, v, current_h / 2.0, u_half, v_half);
					RK4_Step(x + current_h / 2.0, u_half, v_half, current_h / 2.0, u_half2, v_half2);

					// оценка локальной погрешности
					double err_u = Math::Abs(u_h - u_half2) / 15.0;
					double err_v = Math::Abs(v_h - v_half2) / 15.0;
					olp = (err_u > err_v) ? err_u : err_v;

					// контроль погрешности
					if (olp > eps_olp && current_h > 1e-15) {
						current_h /= 2.0;
						total_divisions++;
						current_c1 = 1;
						continue;
					}
				}
				else {
					u_half2 = u_h; // для неадаптивного метода просто копируем результат
					v_half2 = v_h;
					olp = 0.0; // погрешность не оцениваем
				}

				x += current_h;

				u = isAdaptive ? u_half2 : u_h;
				v = isAdaptive ? v_half2 : v_h;

				list_u->Add(x, u);
				list_v->Add(x, v);
				list_phase->Add(u, v);

				if (olp > max_olp) {
					max_olp = olp;
					x_max_olp = x;
				}

				if (current_h > max_h) {
					max_h = current_h;
					x_max_h = x;
				}
				if (current_h < min_h) {
					min_h = current_h;
					x_min_h = x;
				}

				current_c2 = 0;
				if (isAdaptive && olp < eps_olp / 32.0 && x < b - eps_border) {
					current_h *= 2.0;
					total_doublings++;
					current_c2 = 1;
				}

				int rowIdx = dataGridView1->Rows->Add();
				dataGridView1->Rows[rowIdx]->Cells[0]->Value = i;
				dataGridView1->Rows[rowIdx]->Cells[1]->Value = x;
				dataGridView1->Rows[rowIdx]->Cells[2]->Value = u_h;
				dataGridView1->Rows[rowIdx]->Cells[3]->Value = isAdaptive ? (Object^)u_half2 : nullptr;
				dataGridView1->Rows[rowIdx]->Cells[4]->Value = isAdaptive ? (Object^)(u_h - u_half2) : nullptr;
				dataGridView1->Rows[rowIdx]->Cells[5]->Value = isAdaptive ? olp : 0.0;
				dataGridView1->Rows[rowIdx]->Cells[6]->Value = current_h;
				dataGridView1->Rows[rowIdx]->Cells[7]->Value = current_c1;
				dataGridView1->Rows[rowIdx]->Cells[8]->Value = current_c2;
				if (radioTest->Checked) {
					double u_exact = u0 * Math::Exp(Math::Pow(-1.0, N_var) * (N_var / 2.0) * x);
					double abs_error = Math::Abs(u_exact - u);

					dataGridView1->Rows[rowIdx]->Cells[9]->Value = u_exact;
					dataGridView1->Rows[rowIdx]->Cells[10]->Value = abs_error;

					if (abs_error > max_global_err) {
						max_global_err = abs_error;
						x_max_err = x;
					}
					list_exact->Add(x, u_exact);
				}

				i++;
				current_c1 = 0;
			}
			dataGridView1->Visible = true;
			UpdateGraph();

			// формирование отчета по ТЗ
			String^ report = "Итоговые данные:\n";
			report += "Число шагов (n) = " + i + "\n";
			report += "b - xn = " + (b - x).ToString("E2") + "\n";
			report += "max |ОЛП| = " + max_olp.ToString("F12") + " при x = " + x_max_olp + "\n";
			report += "Общее число удвоений (C2) = " + total_doublings + "\n";
			report += "Общее число делений (C1) = " + total_divisions + "\n";
			report += "max hi = " + max_h + " при x = " + x_max_h + "\n";
			report += "min hi = " + min_h + " при x = " + x_min_h + "\n";

			if (radioTest->Checked) {
				report += "Для тестовой задачи: max |ui - vi| = " + max_global_err.ToString("E3") + " при x = " + x_max_err;
			}

			Form^ statsForm = gcnew Form();
			statsForm->Text = "Итоговая статистика и результаты расчета";
			statsForm->Size = System::Drawing::Size(600, 450); // Сразу задаем размер побольше
			statsForm->StartPosition = FormStartPosition::CenterParent;
			statsForm->MinimumSize = System::Drawing::Size(400, 300);

			// Используем RichTextBox, чтобы текст можно было выделять и копировать
			RichTextBox^ rtb = gcnew RichTextBox();
			rtb->Dock = DockStyle::Fill;
			rtb->ReadOnly = true;
			rtb->BackColor = Color::White;
			rtb->Text = report;
			// Моноширинный шрифт Consolas идеален для цифр и табличных данных
			rtb->Font = gcnew System::Drawing::Font("Consolas", 12);

			statsForm->Controls->Add(rtb);
			statsForm->ShowDialog(); // Показываем окно
		}
		catch (Exception^ ex) {
			dataGridView1->Visible = true;
			MessageBox::Show("Ошибка ввода: " + ex->Message);
		}
	}

		   void UpdateGraph() {
			   GraphPane^ panel = zedGraphControl1->GraphPane;
			   panel->CurveList->Clear();

			   panel->XAxis->Scale->MinAuto = true;
			   panel->XAxis->Scale->MaxAuto = true;
			   panel->YAxis->Scale->MinAuto = true;
			   panel->YAxis->Scale->MaxAuto = true;
			   if (rbPhase->Checked) {
				   panel->Title->Text = "Фазовый портрет";
				   panel->XAxis->Title->Text = "Смещение u";
				   panel->YAxis->Title->Text = "Скорость u'";
				   panel->AddCurve("u'(u)", list_phase, Color::Green, SymbolType::None);
			   }
			   else if (rbU->Checked) {
				   panel->XAxis->Title->Text = "Время x";
				   panel->YAxis->Title->Text = "Смещение U";

				   if (radioTest->Checked) {
					   panel->Title->Text = "Тестовая задача: Сравнение U(x)";

					   LineItem^ curveExact = panel->AddCurve("Точное U(x)", list_exact, Color::Blue, SymbolType::None);
					   curveExact->Line->Style = System::Drawing::Drawing2D::DashStyle::Dash; 
					   curveExact->Line->Width = 2.0f; 
					   LineItem^ curveRK = panel->AddCurve("RK4 U(x)", list_u, Color::Red, SymbolType::Circle);
					   curveRK->Symbol->Size = 4.0f; 
					   curveRK->Symbol->Fill->Type = FillType::Solid; 
					   curveRK->Line->Width = 1.0f;
				   }
				   else {
					   panel->Title->Text = "Основная задача: Смещение U(x)";
					   panel->AddCurve("U(x)", list_u, Color::Red, SymbolType::None);
				   }
			   }
			   else if (rbV->Checked) {
				   panel->XAxis->Title->Text = "Время x";
				   panel->YAxis->Title->Text = "Скорость U'";
				   panel->Title->Text = (radioTest->Checked) ? "Тестовая задача: Скорость" : "Основная задача: Скорость U'(x)";

				   panel->AddCurve("U'(x)", list_v, Color::Blue, SymbolType::None);
			   }
			   // Вызываем метод AxisChange (), чтобы обновить данные об осях. 
			   // В противном случае на рисунке будет показана только часть графика, 
			   // которая умещается в интервалы по осям, установленные по умолчанию
			   zedGraphControl1->AxisChange();
			   // Обновляем график
			   zedGraphControl1->Invalidate();
		   }

	private: System::Void zedGraphControl1_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		UpdateGraph();
	}
	private: System::Void checkPhase_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		UpdateGraph();
	}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBoxN_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	UpdateGraph();
}

private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void rbU_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	UpdateGraph();
}

private: System::Void rbV_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	UpdateGraph();
}

private: System::Void rbPhase_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	UpdateGraph();
}
};
}
