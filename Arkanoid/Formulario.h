#pragma once
#include "Circulo.h"
#include "Rectangulo.h"

namespace Arkanoid {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Formulario
	/// </summary>
	public ref class Formulario : public System::Windows::Forms::Form
	{
		Circulo* objCirculo = new Circulo();
		Rectangulo* objRectangulo = new Rectangulo();
	public:
		Formulario(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Formulario()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Formulario::timer1_Tick);
			// 
			// Formulario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(440, 388);
			this->Name = L"Formulario";
			this->Text = L"Formulario";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Formulario::MoverTeclas);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//This llama a las propiedades del formulario
		Graphics^ g = this->CreateGraphics();
		//Almacena espacio para un buffer
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		//buffer para crear un buffer del mismo tamaño del canvas principal
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::Black);
		objCirculo->dibujar(buffer->Graphics);
		objRectangulo->dibujar(buffer->Graphics);
		objCirculo->mover(this->Width, objRectangulo->getY(), objRectangulo->getX(), objRectangulo->getTotalX());
		objRectangulo->setY(this->Height);
		//renderizar
		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}
	private: System::Void MoverTeclas(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Right:
			objRectangulo->mover(true, this->Width);
			break;
		case Keys::Left:
			objRectangulo->mover(false, this->Width);
			break;
		}
	}
	};
}
