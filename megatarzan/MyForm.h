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
		int nivelactual = 1;
		CColision *colision;
		CJugador *jugador;
		CEnemigo *enemigo;
		CStage *fondoMina;
		CStage *plataformaMina;
		CStage *fondoBosque;
		CStage *plataformaBosque;
		CStage *fondoCielo1;
		CStage *fondoCielo2;
		CArregloBalas *oArregloBalas;

		Bitmap ^bmpJugador = gcnew Bitmap("megaman.bmp");
		Bitmap ^bmpFondoMina = gcnew Bitmap("fondo_mina.bmp");
		Bitmap ^bmpPlataformaMina = gcnew Bitmap("plataforma_mina.bmp");
		Bitmap ^bmpBalaEnemigo = gcnew Bitmap("bala.bmp");
		Bitmap ^bmpEnemigo = gcnew Bitmap("enemigo.bmp");
		Bitmap ^bmpPlataformaBosque = gcnew Bitmap("plataforma_bosque.bmp");
		Bitmap ^bmpFondoBosque = gcnew Bitmap("fondo_bosque.bmp");
		Bitmap ^bmpFondoCielo = gcnew Bitmap("fondo_cielo.bmp");

		MyForm(void)
		{
			InitializeComponent();

			colision = new CColision();

			jugador = new CJugador(100, 30);
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(0, 0));

			enemigo = new CEnemigo(1000, 404);
			bmpEnemigo->MakeTransparent(bmpEnemigo->GetPixel(0, 0));

			fondoMina = new CStage(0, 250, 256, 1792, 5);
			plataformaMina = new CStage(0, 0, 353, 1792, 10);
			bmpPlataformaMina->MakeTransparent(bmpPlataformaMina->GetPixel(0, 0));

			fondoBosque = new CStage(0, 0, 300, 1792, 5);
			plataformaBosque = new CStage(0, 0, 353, 1792, 10);
			bmpPlataformaBosque->MakeTransparent(bmpPlataformaBosque->GetPixel(0, 0));

			fondoCielo1 = new CStage(0, 0, 353, 768, -20);
			fondoCielo2 = new CStage(712, 0, 353, 768, -20);

			bmpBalaEnemigo->MakeTransparent(bmpBalaEnemigo->GetPixel(0, 4));
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
			this->ClientSize = System::Drawing::Size(1567, 683);
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
			if (nivelactual == 3) {
		case Keys::Up:
			jugador->saltar();
			break;
		case Keys::Down:
			jugador->direccion = dirs::down;
			break;
			}
		case Keys::Right:
			jugador->direccion = dirs::right;
			break;
		case Keys::Left:
			jugador->direccion = dirs::left;
			break;
		default:
			break;
		}
		if (e->KeyCode == Keys::A && nivelactual != 1) // cambio (temporal) de niveles con A S D
			nivelactual = 1;
		else if (e->KeyCode == Keys::S && nivelactual != 2)
			nivelactual = 2;
		else if (e->KeyCode == Keys::D && nivelactual != 3)
			nivelactual = 3;
		if (e->KeyCode == Keys::Space)
			jugador->disparar(oArregloBalas);
		if (e->KeyCode == Keys::Up && nivelactual != 3)
			jugador->saltar();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^canvas = this->CreateGraphics();
		BufferedGraphicsContext ^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics ^buffer = espacio->Allocate(canvas, this->ClientRectangle);
		switch(nivelactual)
		{
		case 1:
			fondoMina->mover(buffer, bmpFondoMina, jugador->getX(), 0, 0);
			plataformaMina->mover(buffer, bmpPlataformaMina, jugador->getX(), 0, 0);
			jugador->mover(buffer, bmpJugador);
			enemigo->mover(buffer, bmpEnemigo, oArregloBalas, plataformaMina);
			oArregloBalas->moverBalas(buffer, bmpBalaEnemigo);
			break;
		case 2:
			fondoBosque->mover(buffer, bmpFondoBosque, jugador->getX(), 0, 0);
			plataformaBosque->mover(buffer, bmpPlataformaBosque, jugador->getX(), 0, 0);
			jugador->mover(buffer, bmpJugador);
			break;
		case 3:
			// TODO -- nivel subaquatico
			break;
		}
		buffer->Render(canvas);
		delete buffer;
		delete espacio;
		delete canvas;
	}
	private: System::Void soltarTecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode != Keys::Up && e->KeyCode != Keys::Space)
			jugador->direccion = dirs::none;
	}
	};
}
