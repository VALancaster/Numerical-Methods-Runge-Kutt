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
	private: System::Windows::Forms::CheckBox^ checkPhase;
	private: System::Windows::Forms::TextBox^ textBoxN;




	private: System::Windows::Forms::TextBox^ textBoxEps;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::CheckBox^ checkAdaptive;
	private: System::Windows::Forms::TextBox^ textBoxEpsB;
	private: System::Windows::Forms::Label^ label4;


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
			   this->checkPhase = (gcnew System::Windows::Forms::CheckBox());
			   this->textBoxN = (gcnew System::Windows::Forms::TextBox());
			   this->textBoxEps = (gcnew System::Windows::Forms::TextBox());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
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
			   this->zedGraphControl1->Size = System::Drawing::Size(689, 360);
			   this->zedGraphControl1->TabIndex = 0;
			   this->zedGraphControl1->Load += gcnew System::EventHandler(this, &MyForm::zedGraphControl1_Load);
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(1108, 15);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(142, 29);
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
			   this->dataGridView1->Size = System::Drawing::Size(689, 360);
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
			   this->label2->Location = System::Drawing::Point(134, 26);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(13, 13);
			   this->label2->TabIndex = 5;
			   this->label2->Text = L"b";
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(153, 19);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(49, 20);
			   this->textBox2->TabIndex = 6;
			   this->textBox2->Text = L"1";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(222, 26);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(13, 13);
			   this->label3->TabIndex = 7;
			   this->label3->Text = L"h";
			   // 
			   // textBox3
			   // 
			   this->textBox3->Location = System::Drawing::Point(241, 19);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(61, 20);
			   this->textBox3->TabIndex = 8;
			   this->textBox3->Text = L"0,1";
			   // 
			   // radioTest
			   // 
			   this->radioTest->AutoSize = true;
			   this->radioTest->Location = System::Drawing::Point(911, 18);
			   this->radioTest->Name = L"radioTest";
			   this->radioTest->Size = System::Drawing::Size(111, 17);
			   this->radioTest->TabIndex = 14;
			   this->radioTest->TabStop = true;
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
			   this->radioMain->TabStop = true;
			   this->radioMain->Text = L"Основная задача";
			   this->radioMain->UseVisualStyleBackColor = true;
			   // 
			   // checkPhase
			   // 
			   this->checkPhase->AutoSize = true;
			   this->checkPhase->Location = System::Drawing::Point(752, 22);
			   this->checkPhase->Name = L"checkPhase";
			   this->checkPhase->Size = System::Drawing::Size(118, 17);
			   this->checkPhase->TabIndex = 16;
			   this->checkPhase->Text = L"Фазовый портрет";
			   this->checkPhase->UseVisualStyleBackColor = true;
			   this->checkPhase->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkPhase_CheckedChanged);
			   // 
			   // textBoxN
			   // 
			   this->textBoxN->Location = System::Drawing::Point(592, 86);
			   this->textBoxN->Name = L"textBoxN";
			   this->textBoxN->Size = System::Drawing::Size(100, 20);
			   this->textBoxN->TabIndex = 17;
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
			   this->panel1->Controls->Add(this->label4);
			   this->panel1->Controls->Add(this->textBoxEpsB);
			   this->panel1->Controls->Add(this->checkAdaptive);
			   this->panel1->Controls->Add(this->checkPhase);
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
			   this->panel1->Location = System::Drawing::Point(0, 366);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(1390, 186);
			   this->panel1->TabIndex = 21;
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
			   this->textBoxEpsB->Text = L"1e-14";
			   // 
			   // checkAdaptive
			   // 
			   this->checkAdaptive->AutoSize = true;
			   this->checkAdaptive->Checked = true;
			   this->checkAdaptive->CheckState = System::Windows::Forms::CheckState::Checked;
			   this->checkAdaptive->Location = System::Drawing::Point(752, 55);
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
			   this->tableLayoutPanel1->Size = System::Drawing::Size(1390, 366);
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
		double m_val = 0.01;
		double k_val = 2.0;
		double ks_val = 2.0;
		double c_val = 0.15;

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

			double u0 = 10.0; // u0
			double v0 = 0.0; // u'0
			double h_start = Convert::ToDouble(textBox3->Text->Replace(".", ",")); // начальный шаг
			double a = Convert::ToDouble(textBox1->Text->Replace(".", ",")); // левая граница
			double b = Convert::ToDouble(textBox2->Text->Replace(".", ",")); // правая граница

			double eps_olp = Convert::ToDouble(textBoxEps->Text->Replace(".", ",")); // параметр контроля локальное погрешности
			double eps_border = Convert::ToDouble(textBoxEpsB->Text->Replace(".", ",")); // параметр контроля выхода за правую границу

			int N_var = Convert::ToInt32(textBoxN->Text);
			int N_max = 100000; // максимальное количество шагов
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

				if (radioTest->Checked) {
					double u_exact = 10.0 * Math::Exp(Math::Pow(-1.0, N_var) * (N_var / 2.0) * x);
					double abs_error = Math::Abs(u_exact - u_h);

					int rowIdx = dataGridView1->Rows->Add();
					dataGridView1->Rows[rowIdx]->Cells[0]->Value = i;
					dataGridView1->Rows[rowIdx]->Cells[1]->Value = x;
					dataGridView1->Rows[rowIdx]->Cells[2]->Value = u_h;
					dataGridView1->Rows[rowIdx]->Cells[3]->Value = isAdaptive ? (Object^)u_half2 : nullptr;
					dataGridView1->Rows[rowIdx]->Cells[4]->Value = isAdaptive ? (Object^)(u_h - u_half2) : nullptr;
					dataGridView1->Rows[rowIdx]->Cells[5]->Value = isAdaptive ? olp : 0.0;
					dataGridView1->Rows[rowIdx]->Cells[6]->Value = current_h;
					dataGridView1->Rows[rowIdx]->Cells[7]->Value = total_divisions;
					dataGridView1->Rows[rowIdx]->Cells[8]->Value = total_doublings;

					dataGridView1->Rows[rowIdx]->Cells[9]->Value = u_exact;
					dataGridView1->Rows[rowIdx]->Cells[10]->Value = abs_error;

					if (abs_error > max_global_err) {
						max_global_err = abs_error;
						x_max_err = x;
					}
					list_exact->Add(x, u_exact);
				}
				else {
					int rowIdx = dataGridView1->Rows->Add();
					dataGridView1->Rows[rowIdx]->Cells[0]->Value = i;
					dataGridView1->Rows[rowIdx]->Cells[1]->Value = x;
					dataGridView1->Rows[rowIdx]->Cells[2]->Value = u_h;
					dataGridView1->Rows[rowIdx]->Cells[3]->Value = isAdaptive ? (Object^)u_half2 : nullptr;
					dataGridView1->Rows[rowIdx]->Cells[4]->Value = isAdaptive ? (Object^)(u_h - u_half2) : nullptr;
					dataGridView1->Rows[rowIdx]->Cells[5]->Value = isAdaptive ? olp : 0.0;
					dataGridView1->Rows[rowIdx]->Cells[6]->Value = current_h;
					dataGridView1->Rows[rowIdx]->Cells[7]->Value = total_divisions;
					dataGridView1->Rows[rowIdx]->Cells[8]->Value = total_doublings;
				}

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

				i++;

				if (isAdaptive && olp < eps_olp / 32.0 && x < b - eps_border) {
					current_h *= 2.0;
					total_doublings++;
				}
			}
			//list_u->Add(x, u);
			//list_v->Add(x, v);
			//list_phase->Add(u, v);

			//if (radioTest->Checked) {
			//	double u_exact_final = 10.0 * Math::Exp(Math::Pow(-1.0, N_var) * (N_var / 2.0) * x);
			//	list_exact->Add(x, u_exact_final);
			//}

			dataGridView1->Visible = true;
			UpdateGraph();

			// формирование отчета по ТЗ
			String^ report = "Итоговые данные:\n";
			report += "n = " + i + "\n";
			report += "b - xn = " + (b - x).ToString("E2") + "\n";
			report += "max |ОЛП| = " + max_olp.ToString("E3") + " при x = " + x_max_olp + "\n";
			report += "Общее число удвоений (C2) = " + total_doublings + "\n";
			report += "Общее число делений (C1) = " + total_divisions + "\n";
			report += "max hi = " + max_h + " при x = " + x_max_h + "\n";
			report += "min hi = " + min_h + " при x = " + x_min_h + "\n";

			if (radioTest->Checked) {
				report += "Для тестовой задачи: max |ui - vi| = " + max_global_err.ToString("E3") + " при x = " + x_max_err;
			}

			MessageBox::Show(report, "Результаты по ТЗ");
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
			   if (checkPhase->Checked) {
				   panel->Title->Text = "Фазовый портрет";
				   panel->XAxis->Title->Text = "Смещение u";
				   panel->YAxis->Title->Text = "Скорость v";
				   panel->AddCurve("v(u)", list_phase, Color::Green, SymbolType::None);
			   }
			   else {
				   panel->XAxis->Title->Text = "Время x";

				   if (radioTest->Checked) {
					   panel->Title->Text = "Тестовая задача: сравнение решений";
					   panel->YAxis->Title->Text = "u";

					   LineItem^ curveExact = panel->AddCurve("Точное решение", list_exact, Color::Blue, SymbolType::None);
					   curveExact->Line->Style = System::Drawing::Drawing2D::DashStyle::Dash; 
					   curveExact->Line->Width = 2.0f; 
					   LineItem^ curveRK = panel->AddCurve("Приближенное (RK4)", list_u, Color::Red, SymbolType::Circle);
					   curveRK->Symbol->Size = 4.0f; 
					   curveRK->Symbol->Fill->Type = FillType::Solid; 
					   curveRK->Line->Width = 1.0f;
				   }
				   else {
					   panel->Title->Text = "Динамика системы";
					   panel->YAxis->Title->Text = "u, v";
					   panel->AddCurve("Смещение u(x)", list_u, Color::Red, SymbolType::None);
					   panel->AddCurve("Скорость v(x)", list_v, Color::Blue, SymbolType::None);
				   }
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
};
}
