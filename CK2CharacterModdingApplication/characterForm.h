#pragma once
#include <msclr\marshal_cppstd.h>
#include <Shlwapi.h>
#include "driver.h"

namespace CK2CharacterModdingApplication {

	using namespace System;
    using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace msclr::interop;

	/// <summary>
	/// Summary for characterForm
	/// </summary>
	public ref class characterForm : public System::Windows::Forms::Form {
	public:
		characterForm(void)	{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~characterForm() {
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::TextBox^  outputTextBox;
    private: System::Windows::Forms::Button^  FindProvinces;
    private: System::Windows::Forms::TextBox^  provincePathTextBox;
    private: System::Windows::Forms::FolderBrowserDialog^  provinceFolderBrowser;
    private: System::Windows::Forms::Button^  GenerateCharacters;
    private: System::Windows::Forms::GroupBox^  UpperGroup;
    private: System::Windows::Forms::Button^  characterOutputFolderButton;
    private: System::Windows::Forms::TextBox^  characterFolderTextbox;
    private: System::Windows::Forms::FolderBrowserDialog^  characterFolderBrowser;
    private: System::Windows::Forms::ComboBox^  cultureComboBox;
    private: System::Windows::Forms::Label^  cultureLabel;

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
		void InitializeComponent(void) {
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(characterForm::typeid));
            this->outputTextBox = (gcnew System::Windows::Forms::TextBox());
            this->FindProvinces = (gcnew System::Windows::Forms::Button());
            this->provincePathTextBox = (gcnew System::Windows::Forms::TextBox());
            this->provinceFolderBrowser = (gcnew System::Windows::Forms::FolderBrowserDialog());
            this->GenerateCharacters = (gcnew System::Windows::Forms::Button());
            this->UpperGroup = (gcnew System::Windows::Forms::GroupBox());
            this->cultureLabel = (gcnew System::Windows::Forms::Label());
            this->cultureComboBox = (gcnew System::Windows::Forms::ComboBox());
            this->characterFolderTextbox = (gcnew System::Windows::Forms::TextBox());
            this->characterOutputFolderButton = (gcnew System::Windows::Forms::Button());
            this->characterFolderBrowser = (gcnew System::Windows::Forms::FolderBrowserDialog());
            this->UpperGroup->SuspendLayout();
            this->SuspendLayout();
            // 
            // outputTextBox
            // 
            this->outputTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                                                                                              | System::Windows::Forms::AnchorStyles::Left)
                                                                                             | System::Windows::Forms::AnchorStyles::Right));
            this->outputTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                                     static_cast<System::Byte>(0)));
            this->outputTextBox->ImeMode = System::Windows::Forms::ImeMode::NoControl;
            this->outputTextBox->Location = System::Drawing::Point(48, 326);
            this->outputTextBox->Margin = System::Windows::Forms::Padding(0);
            this->outputTextBox->Multiline = true;
            this->outputTextBox->Name = L"outputTextBox";
            this->outputTextBox->ReadOnly = true;
            this->outputTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->outputTextBox->Size = System::Drawing::Size(1724, 617);
            this->outputTextBox->TabIndex = 0;
            // 
            // FindProvinces
            // 
            this->FindProvinces->Location = System::Drawing::Point(0, 30);
            this->FindProvinces->Name = L"FindProvinces";
            this->FindProvinces->Size = System::Drawing::Size(310, 44);
            this->FindProvinces->TabIndex = 1;
            this->FindProvinces->Text = L"Choose Province Folder";
            this->FindProvinces->UseVisualStyleBackColor = true;
            this->FindProvinces->Click += gcnew System::EventHandler(this, &characterForm::ChooseProvinceFolder);
            // 
            // provincePathTextBox
            // 
            this->provincePathTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                                                                                                   | System::Windows::Forms::AnchorStyles::Right));
            this->provincePathTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
                                                                           System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->provincePathTextBox->Location = System::Drawing::Point(320, 31);
            this->provincePathTextBox->Name = L"provincePathTextBox";
            this->provincePathTextBox->Size = System::Drawing::Size(1078, 44);
            this->provincePathTextBox->TabIndex = 2;
            // 
            // provinceFolderBrowser
            // 
            this->provinceFolderBrowser->SelectedPath = L"C:\\Users\\Aristotle\\Documents\\Paradox Interactive\\Crusader Kings II\\mod\\SmallConti"
                L"nent\\history\\provinces";
            // 
            // GenerateCharacters
            // 
            this->GenerateCharacters->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->GenerateCharacters->Location = System::Drawing::Point(1402, 198);
            this->GenerateCharacters->Name = L"GenerateCharacters";
            this->GenerateCharacters->Size = System::Drawing::Size(316, 44);
            this->GenerateCharacters->TabIndex = 3;
            this->GenerateCharacters->Text = L"Generate Characters";
            this->GenerateCharacters->UseVisualStyleBackColor = true;
            this->GenerateCharacters->Click += gcnew System::EventHandler(this, &characterForm::GenerateCharacters_Click);
            // 
            // UpperGroup
            // 
            this->UpperGroup->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                                                                                          | System::Windows::Forms::AnchorStyles::Right));
            this->UpperGroup->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->UpperGroup->BackColor = System::Drawing::SystemColors::Control;
            this->UpperGroup->Controls->Add(this->cultureLabel);
            this->UpperGroup->Controls->Add(this->cultureComboBox);
            this->UpperGroup->Controls->Add(this->characterFolderTextbox);
            this->UpperGroup->Controls->Add(this->characterOutputFolderButton);
            this->UpperGroup->Controls->Add(this->FindProvinces);
            this->UpperGroup->Controls->Add(this->GenerateCharacters);
            this->UpperGroup->Controls->Add(this->provincePathTextBox);
            this->UpperGroup->Location = System::Drawing::Point(48, 12);
            this->UpperGroup->Name = L"UpperGroup";
            this->UpperGroup->Size = System::Drawing::Size(1724, 248);
            this->UpperGroup->TabIndex = 4;
            this->UpperGroup->TabStop = false;
            // 
            // cultureLabel
            // 
            this->cultureLabel->AutoSize = true;
            this->cultureLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                                    static_cast<System::Byte>(0)));
            this->cultureLabel->Location = System::Drawing::Point(122, 181);
            this->cultureLabel->Name = L"cultureLabel";
            this->cultureLabel->Size = System::Drawing::Size(188, 26);
            this->cultureLabel->TabIndex = 7;
            this->cultureLabel->Text = L"Culture Name File";
            // 
            // cultureComboBox
            // 
            this->cultureComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                                       static_cast<System::Byte>(0)));
            this->cultureComboBox->FormattingEnabled = true;
            this->cultureComboBox->Location = System::Drawing::Point(320, 169);
            this->cultureComboBox->Name = L"cultureComboBox";
            this->cultureComboBox->Size = System::Drawing::Size(243, 45);
            this->cultureComboBox->TabIndex = 6;
            this->cultureComboBox->DropDown += gcnew System::EventHandler(this, &characterForm::ClickCultureDropDown);
            // 
            // characterFolderTextbox
            // 
            this->characterFolderTextbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                                                                                                      | System::Windows::Forms::AnchorStyles::Right));
            this->characterFolderTextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
                                                                              System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->characterFolderTextbox->Location = System::Drawing::Point(320, 97);
            this->characterFolderTextbox->Name = L"characterFolderTextbox";
            this->characterFolderTextbox->Size = System::Drawing::Size(1078, 44);
            this->characterFolderTextbox->TabIndex = 5;
            // 
            // characterOutputFolderButton
            // 
            this->characterOutputFolderButton->Location = System::Drawing::Point(0, 97);
            this->characterOutputFolderButton->Name = L"characterOutputFolderButton";
            this->characterOutputFolderButton->Size = System::Drawing::Size(310, 44);
            this->characterOutputFolderButton->TabIndex = 4;
            this->characterOutputFolderButton->Text = L"Choose Ouptput Folder";
            this->characterOutputFolderButton->UseVisualStyleBackColor = true;
            this->characterOutputFolderButton->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &characterForm::CharacterOutputFolderClick);
            // 
            // characterFolderBrowser
            // 
            this->characterFolderBrowser->SelectedPath = L"C:\\Users\\Aristotle\\Documents\\Aristotle\\Programming\\CK2Modding\\CK2CharacterModding"
                L"Application\\CK2CharacterModdingApplication\\output";
            // 
            // characterForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Control;
            this->ClientSize = System::Drawing::Size(1894, 1009);
            this->Controls->Add(this->UpperGroup);
            this->Controls->Add(this->outputTextBox);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"characterForm";
            this->Text = L"CK2 Character Creator";
            this->UpperGroup->ResumeLayout(false);
            this->UpperGroup->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void GenerateCharacters_Click(System::Object^  sender, System::EventArgs^  e) {
        // Get miscellaneous attributes Singleton reference
        miscellaneousAttributes& miscAttr = miscellaneousAttributes::get_instance();

        // Check if specified province and output directories are valid
        if (Directory::Exists(provincePathTextBox->Text)) {
            outputTextBox->AppendText("Valid province folder path\r\n");
        }
        else {
            outputTextBox->AppendText("Invalid province folder path!\r\n");
            return;
        }
        if (Directory::Exists(characterFolderTextbox->Text)) {
            outputTextBox->AppendText("Valid output folder path\r\n");
            miscAttr.characterOutputPath = marshal_as<string>(characterFolderTextbox->Text);
        }
        else {
            outputTextBox->AppendText("Invalid output folder path!\r\n");
            return;
        }

        // Check if culture name file is valid
        LPCTSTR cultureNamePath = PrintFullPathCultureNames(marshal_as<string>(cultureComboBox->Text));
        DWORD dwAttrib = GetFileAttributes(cultureNamePath);
        if (dwAttrib != INVALID_FILE_ATTRIBUTES && !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY)) {
            outputTextBox->AppendText("Valid culture names file\r\n");
        }
        else {
            outputTextBox->AppendText("Invalid culture names file!\r\n");
            return;
        }

        // Display the provinces IDs for which characters will be generated
        string provinceDirectory = marshal_as<string>(provincePathTextBox->Text);
        vector<string> provinceVector = readProvinces(provinceDirectory);
        outputTextBox->AppendText("Creating characters for the following provinces:\r\n");
        for (string i : provinceVector) {
            String ^s = gcnew String(i.c_str());
            outputTextBox->AppendText(s + "\r\n");
        }

        // Generate names Lists
        GenerateNamesList(miscAttr.cultureNamesPath);
        outputTextBox->AppendText("Succesfully Generated Names list!\r\n");

        // Generate characters and produce the character files
        CreateCharacterFiles(miscAttr.characterOutputPath);
        outputTextBox->AppendText("Succesfully Generated Characters!\r\n");
    }

    private: System::Void ChooseProvinceFolder(System::Object^  sender, System::EventArgs^  e) {
        if (provinceFolderBrowser->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            provincePathTextBox->Text = provinceFolderBrowser->SelectedPath;
        }
    }

    private: System::Void CharacterOutputFolderClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
        if (characterFolderBrowser->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            characterFolderTextbox->Text = characterFolderBrowser->SelectedPath;
        }
    }

    private: System::Void ClickCultureDropDown(System::Object^  sender, System::EventArgs^  e) {
        vector<string> culturesVec = availableCultures();
        cultureComboBox->Items->Clear();
        for (auto i : culturesVec) {
            String^ culture = gcnew String(i.c_str());
            cultureComboBox->Items->Add(culture);
        }
    }








};
}
