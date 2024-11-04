#pragma once
#include "Jugador.h"

namespace SpritesProject {

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
	//Creamos el objeto jugador y el bitmap de Goku
	private:
		Jugador^ objJugador = gcnew Jugador(50, 50);
		Bitmap^ bmpJugador = gcnew Bitmap("Goku.png");
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
			this->ClientSize = System::Drawing::Size(402, 426);
			this->Name = L"Formulario";
			this->Text = L"Formulario";
			this->Load += gcnew System::EventHandler(this, &Formulario::Formulario_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Formulario::presionarTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Formulario::soltarTecla);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Formulario_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Aqui vamos a hacer la magia
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		objJugador->mover(buffer, bmpJugador);

		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}
	private: System::Void soltarTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		objJugador->direccion = Direcciones::Ninguna;
	}
	private: System::Void presionarTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Left:
			objJugador->direccion = Direcciones::Izquierda;
			break;
		case Keys::Right:
			objJugador->direccion = Direcciones::Derecha;
			break;
		case Keys::Up:
			objJugador->direccion = Direcciones::Arriba;
			break;
		case Keys::Down:
			objJugador->direccion = Direcciones::Abajo;
			break;
		}
	}
	};
}
