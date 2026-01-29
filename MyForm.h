#pragma once

#include <iostream>
#include <string>

#include <msclr/marshal_cppstd.h>

#include "Utils.hpp"
#include "Operations.hpp"
#include "Casting.hpp"

namespace osn {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl1;
	private: System::Windows::Forms::TextBox^ firstNumberInput;


	private: System::Windows::Forms::Label^ lbl2;
	private: System::Windows::Forms::TextBox^ secondNumberInput;


	private: System::Windows::Forms::Button^ sumBtn;
	private: System::Windows::Forms::Button^ minBtn;
	private: System::Windows::Forms::Button^ mulBtn;
	private: System::Windows::Forms::Button^ divBtn;
	private: System::Windows::Forms::Label^ lbl3;
	private: System::Windows::Forms::TextBox^ resultInput;
	private: System::Windows::Forms::Label^ firstError;
	private: System::Windows::Forms::Label^ secondError;
	private: System::Windows::Forms::LinkLabel^ help;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->lbl1 = (gcnew System::Windows::Forms::Label());
			this->firstNumberInput = (gcnew System::Windows::Forms::TextBox());
			this->lbl2 = (gcnew System::Windows::Forms::Label());
			this->secondNumberInput = (gcnew System::Windows::Forms::TextBox());
			this->sumBtn = (gcnew System::Windows::Forms::Button());
			this->minBtn = (gcnew System::Windows::Forms::Button());
			this->mulBtn = (gcnew System::Windows::Forms::Button());
			this->divBtn = (gcnew System::Windows::Forms::Button());
			this->lbl3 = (gcnew System::Windows::Forms::Label());
			this->resultInput = (gcnew System::Windows::Forms::TextBox());
			this->firstError = (gcnew System::Windows::Forms::Label());
			this->secondError = (gcnew System::Windows::Forms::Label());
			this->help = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// lbl1
			// 
			this->lbl1->AutoSize = true;
			this->lbl1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl1->Location = System::Drawing::Point(13, 13);
			this->lbl1->Name = L"lbl1";
			this->lbl1->Size = System::Drawing::Size(371, 22);
			this->lbl1->TabIndex = 0;
			this->lbl1->Text = L"Введите число в 2-ой системе счисления:";
			// 
			// firstNumberInput
			// 
			this->firstNumberInput->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->firstNumberInput->Location = System::Drawing::Point(17, 38);
			this->firstNumberInput->MaxLength = 20;
			this->firstNumberInput->Name = L"firstNumberInput";
			this->firstNumberInput->Size = System::Drawing::Size(312, 26);
			this->firstNumberInput->TabIndex = 1;
			// 
			// lbl2
			// 
			this->lbl2->AutoSize = true;
			this->lbl2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl2->Location = System::Drawing::Point(13, 102);
			this->lbl2->Name = L"lbl2";
			this->lbl2->Size = System::Drawing::Size(381, 22);
			this->lbl2->TabIndex = 2;
			this->lbl2->Text = L"Введите число в 16-ой системе счисления:";
			// 
			// secondNumberInput
			// 
			this->secondNumberInput->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->secondNumberInput->Location = System::Drawing::Point(17, 127);
			this->secondNumberInput->MaxLength = 20;
			this->secondNumberInput->Name = L"secondNumberInput";
			this->secondNumberInput->Size = System::Drawing::Size(312, 26);
			this->secondNumberInput->TabIndex = 3;
			// 
			// sumBtn
			// 
			this->sumBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->sumBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->sumBtn->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sumBtn->Location = System::Drawing::Point(17, 318);
			this->sumBtn->Name = L"sumBtn";
			this->sumBtn->Size = System::Drawing::Size(100, 100);
			this->sumBtn->TabIndex = 4;
			this->sumBtn->Text = L"Сложить";
			this->sumBtn->UseVisualStyleBackColor = false;
			this->sumBtn->Click += gcnew System::EventHandler(this, &MyForm::sumBtnClick);
			// 
			// minBtn
			// 
			this->minBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->minBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->minBtn->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->minBtn->Location = System::Drawing::Point(123, 318);
			this->minBtn->Name = L"minBtn";
			this->minBtn->Size = System::Drawing::Size(100, 100);
			this->minBtn->TabIndex = 5;
			this->minBtn->Text = L"Вычесть";
			this->minBtn->UseVisualStyleBackColor = false;
			this->minBtn->Click += gcnew System::EventHandler(this, &MyForm::minBtnClick);
			// 
			// mulBtn
			// 
			this->mulBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->mulBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mulBtn->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mulBtn->Location = System::Drawing::Point(229, 318);
			this->mulBtn->Name = L"mulBtn";
			this->mulBtn->Size = System::Drawing::Size(100, 100);
			this->mulBtn->TabIndex = 6;
			this->mulBtn->Text = L"Умножить";
			this->mulBtn->UseVisualStyleBackColor = false;
			this->mulBtn->Click += gcnew System::EventHandler(this, &MyForm::mulBtnClick);
			// 
			// divBtn
			// 
			this->divBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->divBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->divBtn->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->divBtn->Location = System::Drawing::Point(335, 318);
			this->divBtn->Name = L"divBtn";
			this->divBtn->Size = System::Drawing::Size(100, 100);
			this->divBtn->TabIndex = 7;
			this->divBtn->Text = L"Делить\r\n";
			this->divBtn->UseVisualStyleBackColor = false;
			this->divBtn->Click += gcnew System::EventHandler(this, &MyForm::divBtnClick);
			// 
			// lbl3
			// 
			this->lbl3->AutoSize = true;
			this->lbl3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl3->Location = System::Drawing::Point(13, 191);
			this->lbl3->Name = L"lbl3";
			this->lbl3->Size = System::Drawing::Size(189, 22);
			this->lbl3->TabIndex = 8;
			this->lbl3->Text = L"Результат операции:";
			// 
			// resultInput
			// 
			this->resultInput->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->resultInput->Location = System::Drawing::Point(17, 216);
			this->resultInput->Name = L"resultInput";
			this->resultInput->ReadOnly = true;
			this->resultInput->Size = System::Drawing::Size(312, 26);
			this->resultInput->TabIndex = 10;
			// 
			// firstError
			// 
			this->firstError->AutoSize = true;
			this->firstError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->firstError->ForeColor = System::Drawing::Color::Red;
			this->firstError->Location = System::Drawing::Point(20, 67);
			this->firstError->Name = L"firstError";
			this->firstError->Size = System::Drawing::Size(198, 14);
			this->firstError->TabIndex = 11;
			this->firstError->Text = L"Неправильно задано число в 2-ой СЧ!!!";
			this->firstError->Visible = false;
			// 
			// secondError
			// 
			this->secondError->AutoSize = true;
			this->secondError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->secondError->ForeColor = System::Drawing::Color::Red;
			this->secondError->Location = System::Drawing::Point(20, 160);
			this->secondError->Name = L"secondError";
			this->secondError->Size = System::Drawing::Size(204, 14);
			this->secondError->TabIndex = 12;
			this->secondError->Text = L"Неправильно задано число в 16-ой СЧ!!!";
			this->secondError->Visible = false;
			// 
			// help
			// 
			this->help->AutoSize = true;
			this->help->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->help->Location = System::Drawing::Point(17, 421);
			this->help->Name = L"help";
			this->help->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->help->Size = System::Drawing::Size(46, 14);
			this->help->TabIndex = 13;
			this->help->TabStop = true;
			this->help->Text = L"Справка";
			this->help->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::helpClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(453, 454);
			this->Controls->Add(this->help);
			this->Controls->Add(this->secondError);
			this->Controls->Add(this->firstError);
			this->Controls->Add(this->resultInput);
			this->Controls->Add(this->lbl3);
			this->Controls->Add(this->divBtn);
			this->Controls->Add(this->mulBtn);
			this->Controls->Add(this->minBtn);
			this->Controls->Add(this->sumBtn);
			this->Controls->Add(this->secondNumberInput);
			this->Controls->Add(this->lbl2);
			this->Controls->Add(this->firstNumberInput);
			this->Controls->Add(this->lbl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Калькулятор";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void sumBtnClick(System::Object^ sender, System::EventArgs^ e) {
	firstError->Visible = false;
	secondError->Visible = false;

	auto firstNumber = msclr::interop::marshal_as<std::string>(firstNumberInput->Text);
	auto secondNumber = msclr::interop::marshal_as<std::string>(secondNumberInput->Text);

	bool isCanSum = Utils::isCorrect2(firstNumber) && Utils::isCorrect16(secondNumber);

	if (isCanSum) {
		auto result = Operations::plus(firstNumber, Utils::from16to2(secondNumber));
		resultInput->Text = gcnew String(Utils::from2to16(result).c_str());
	} else {
		if (!Utils::isCorrect2(firstNumber)) {
			firstError->Visible = true;
		}

		if (!Utils::isCorrect16(secondNumber)) {
			secondError->Visible = true;
		}
	}
}

private: System::Void minBtnClick(System::Object^ sender, System::EventArgs^ e) {
	firstError->Visible = false;
	secondError->Visible = false;

	auto firstNumber = msclr::interop::marshal_as<std::string>(firstNumberInput->Text);
	auto secondNumber = msclr::interop::marshal_as<std::string>(secondNumberInput->Text);

	bool isCanMin = Utils::isCorrect2(firstNumber) && Utils::isCorrect16(secondNumber);

	if (isCanMin) {
		auto result = Operations::minus(firstNumber, Utils::from16to2(secondNumber));
		resultInput->Text = gcnew String(Utils::from2to16(result).c_str());
	}
	else {
		if (!Utils::isCorrect2(firstNumber)) {
			firstError->Visible = true;
		}

		if (!Utils::isCorrect16(secondNumber)) {
			secondError->Visible = true;
		}
	}
}

private: System::Void mulBtnClick(System::Object^ sender, System::EventArgs^ e) {
	firstError->Visible = false;
	secondError->Visible = false;

	auto firstNumber = msclr::interop::marshal_as<std::string>(firstNumberInput->Text);
	auto secondNumber = msclr::interop::marshal_as<std::string>(secondNumberInput->Text);

	bool isCanMul = Utils::isCorrect2(firstNumber) && Utils::isCorrect16(secondNumber);

	if (isCanMul) {
		auto result = Operations::multiply(firstNumber, Utils::from16to2(secondNumber));
		resultInput->Text = gcnew String(Utils::from2to16(result).c_str());
	}
	else {
		if (!Utils::isCorrect2(firstNumber)) {
			firstError->Visible = true;
		}

		if (!Utils::isCorrect16(secondNumber)) {
			secondError->Visible = true;
		}
	}
}

private: System::Void divBtnClick(System::Object^ sender, System::EventArgs^ e) {
	firstError->Visible = false;
	secondError->Visible = false;

	auto firstNumber = msclr::interop::marshal_as<std::string>(firstNumberInput->Text);
	auto secondNumber = msclr::interop::marshal_as<std::string>(secondNumberInput->Text);

	bool isCanDiv = Utils::isCorrect2(firstNumber) && Utils::isCorrect16(secondNumber);

	if (isCanDiv) {
		auto result = Operations::divide(firstNumber, Utils::from16to2(secondNumber));
		auto resultString = std::get<0>(result);
		auto resultError = std::get<1>(result);

		if (resultString == "") {
			resultInput->Text = gcnew String(resultError.c_str());
		}
		else {
			resultInput->Text = gcnew String(Utils::from2to16(resultString).c_str());
		}
	}
	else {
		if (!Utils::isCorrect2(firstNumber)) {
			firstError->Visible = true;
		}

		if (!Utils::isCorrect16(secondNumber)) {
			secondError->Visible = true;
		}
	}
}

private: System::Void helpClick(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	System::Diagnostics::Process::Start("S:/projects/c++/osn/help.html");
}
	};	
}
