#pragma once
#include "Jugador.h"
#include "Stage.h"
#include "Colision.h"
#include "Enemigo.h"
#include "Bala.h"
#include "ArregloBalas.h"
namespace megatarzan {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		CColision *colision;
		CJugador *jugador;
		CEnemigo *enemigo;
		CStage *fondo1;
		CStage *plataforma1;
		CArregloBalas *oArregloBalas;

		Bitmap ^bmpJugador = gcnew Bitmap("megaman.bmp");
		Bitmap ^bmpFondo = gcnew Bitmap("fondo_mina.bmp");
		Bitmap ^bmpPlataforma = gcnew Bitmap("plataforma_mina.bmp");
		Bitmap ^bmpBala = gcnew Bitmap("bala.bmp");
		Bitmap ^bmpEnemigo = gcnew Bitmap("enemigo.bmp");

		MyForm(void)
		{
			InitializeComponent();
			colision = new CColision();
			jugador = new CJugador(100, 30);
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(0, 0));
			enemigo = new CEnemigo(1000, 404);
			bmpEnemigo->MakeTransparent(bmpEnemigo->GetPixel(0, 0));
			fondo1 = new CStage(0, 250, 256, 1792, 5);
			plataforma1 = new CStage(0, 0, 353, 1792, 10);
			bmpPlataforma->MakeTransparent(bmpPlataforma->GetPixel(0, 0));
			bmpBala->MakeTransparent(bmpBala->GetPixel(0, 4));
			oArregloBalas = new CArregloBalas();
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
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
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
			this->timer1->Interval = 70;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1181, 683);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::presionarTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::soltarTecla);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void presionarTecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode)
		{
		case Keys::Up:
			jugador->direccion = dirs::up;
			break;
		case Keys::Down:
			jugador->direccion = dirs::down;
			break;
		case Keys::Right:
			jugador->direccion = dirs::right;
			break;
		case Keys::Left:
			jugador->direccion = dirs::left;
			break;
		default:
			break;
		}
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^canvas = this->CreateGraphics();
		BufferedGraphicsContext ^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics ^buffer = espacio->Allocate(canvas, this->ClientRectangle);

		fondo1->mover(buffer, bmpFondo, jugador->getX(), 0, 0);
		plataforma1->mover(buffer, bmpPlataforma, jugador->getX(), 0, 0);
		jugador->mover(buffer, bmpJugador);
		enemigo->mover(buffer, bmpEnemigo, oArregloBalas, plataforma1);
		oArregloBalas->moverBalas(buffer, bmpBala);
		buffer->Render(canvas);
		delete buffer;
		delete espacio;
		delete canvas;
	}
	private: System::Void soltarTecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode != Keys::Up)
			jugador->direccion = dirs::none;
	}
	};
}
