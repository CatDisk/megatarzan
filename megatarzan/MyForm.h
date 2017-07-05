#pragma once
#include "Jugador.h"
#include "Caminante.h"
#include "Nadador.h"
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
		int nivelanterior = 1;

		CJugador *jugador;
		CEnemigo *enemigo;
		CStage *fondoMina;
		CStage *plataformaMina;
		CStage *fondoBosque;
		CStage *plataformaBosque;
		CStage *fondoCielo1;
		CStage *fondoCielo2;
		CStage *fondoMar1;
		CStage *fondoMar2;
		CStage *plataformaMar1;
		CStage *plataformaMar2;
		CArregloBalas *oArregloBalas;

		Bitmap ^bmpJugador = gcnew Bitmap("megaman.bmp");
		Bitmap ^bmpFondoMina = gcnew Bitmap("fondo_mina.bmp");
		Bitmap ^bmpPlataformaMina = gcnew Bitmap("plataforma_mina.bmp");
		Bitmap ^bmpBalaEnemigo = gcnew Bitmap("bala.bmp");
		Bitmap ^bmpEnemigo = gcnew Bitmap("enemigo.bmp");
		Bitmap ^bmpPlataformaBosque = gcnew Bitmap("plataforma_bosque.bmp");
		Bitmap ^bmpFondoBosque = gcnew Bitmap("fondo_bosque.bmp");
		Bitmap ^bmpFondoCielo = gcnew Bitmap("fondo_cielo.bmp");
		Bitmap ^bmpFondoMar = gcnew Bitmap("fondo_mar.bmp");
		Bitmap ^bmpPlataformaMar = gcnew Bitmap("plataforma_mar.bmp");

		MyForm(void)
		{
			InitializeComponent();

			jugador = new CCaminante(0, 0, 472);
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

			fondoMar1 = new CStage(0, 0, 353, 1244, -5);
			fondoMar2 = new CStage(2488, 0, 353, 1244, -5);

			plataformaMar1 = new CStage(0, 0, 353, 1244, -10);
			plataformaMar2 = new CStage(2488, 0, 353, 1244, -10);
			bmpPlataformaMar->MakeTransparent(bmpPlataformaMar->GetPixel(0, 0));

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
		if (e->KeyCode == Keys::Space)
			jugador->disparar(oArregloBalas);
		switch (e->KeyCode)
		{
		case Keys::Up:
				jugador->direccion = dirs::up;
				jugador->saltar();
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
		if (e->KeyCode == Keys::A && nivelactual != 1) // cambio (temporal) de niveles con A S D
			nivelactual = 1;
		else if (e->KeyCode == Keys::S && nivelactual != 2)
			nivelactual = 2;
		else if (e->KeyCode == Keys::D && nivelactual != 3)
			nivelactual = 3;

	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^canvas = this->CreateGraphics();
		BufferedGraphicsContext ^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics ^buffer = espacio->Allocate(canvas, this->ClientRectangle);
		switch(nivelactual)
		{
		case 1:
			if (nivelanterior != nivelactual)
			{
				delete jugador;
				jugador = new CCaminante(100, 30, 472);
				nivelanterior = nivelactual;
			}
			fondoMina->mover(buffer, bmpFondoMina, jugador->getX(), nivelactual, 0);
			plataformaMina->mover(buffer, bmpPlataformaMina, jugador->getX(), nivelactual, 0);
			jugador->mover(buffer, bmpJugador);
			enemigo->mover(buffer, bmpEnemigo, oArregloBalas, plataformaMina);
			oArregloBalas->moverBalas(buffer, bmpBalaEnemigo);
			break;
		case 2:
			if (nivelanterior != nivelactual)
			{
				delete jugador;
				jugador = new CCaminante(100, 30, 450);
				nivelanterior = nivelactual;
			}
			fondoBosque->mover(buffer, bmpFondoBosque, jugador->getX(), nivelactual, 0);
			plataformaBosque->mover(buffer, bmpPlataformaBosque, jugador->getX(), nivelactual, 0);
			jugador->mover(buffer, bmpJugador);
			oArregloBalas->moverBalas(buffer, bmpBalaEnemigo);
			break;
		case 3:
			if (nivelanterior != nivelactual)
			{
				delete jugador;
				jugador = new CNadador(100, 100);
				nivelanterior = nivelactual;
			}
			fondoMar1->mover(buffer, bmpFondoMar, NULL, nivelactual, fondoMar2->getX());
			fondoMar2->mover(buffer, bmpFondoMar, NULL, nivelactual, fondoMar1->getX());
			jugador->mover(buffer, bmpJugador);
			oArregloBalas->moverBalas(buffer, bmpBalaEnemigo);
			plataformaMar1->mover(buffer, bmpPlataformaMar, NULL, nivelactual, plataformaMar2->getX());
			plataformaMar2->mover(buffer, bmpPlataformaMar, NULL, nivelactual, plataformaMar1->getX());
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
		if (nivelactual == 3 && e->KeyCode == Keys::Up)
			jugador->direccion = dirs::none;
	}
	};
}
