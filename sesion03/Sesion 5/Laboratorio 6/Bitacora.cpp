#include "Bitacora.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

namespace EIF201 {
	Bitacora::Bitacora(const std::string& ruta):ruta_(ruta),validas_(0),descartadas_(0)
	{
	}
	bool Bitacora::registrarAve(const std::string & anillo, const std::string & especie, double peso, char sexo, const std::string & fecha)
	{
		std::ofstream ofs(ruta_, std::ios::app);
		if (!ofs.is_open()) return false;
		ofs << anillo << ';' << especie << ';' << peso << ';' << sexo << ';' << fecha << '\n';
		ofs.close();
		return true;
	}
	int Bitacora::cargarTodas(NodoAve*& cabeza)
	{
		try {
			liberarListas(cabeza);
			int contador = 0;
			std::ifstream ifs(ruta_);
			if (!ifs) return 0;
			std::string line;
			auto is_space = [](char ch) {
				return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f' || ch == '\v';
			};
			auto trim = [&](std::string &s) {

				size_t start = 0;
				while (start < s.size() && is_space(s[start])) ++start;
				if (start > 0) s.erase(0, start);

				while (!s.empty() && is_space(s.back())) s.pop_back();
			};
			NodoAve* newHead = nullptr;
			NodoAve* newTail = nullptr;
			while (std::getline(ifs, line)) {
				std::stringstream ss(line);
				std::string anillo, especie, pesoStr, sexoStr, fecha;
				if (!std::getline(ss, anillo, ';')) continue;
				if (!std::getline(ss, especie, ';')) continue;
				if (!std::getline(ss, pesoStr, ';')) continue;
				if (!std::getline(ss, sexoStr, ';')) continue;
				if (!std::getline(ss, fecha, ';')) {

					if (!std::getline(ss, fecha)) fecha = "";
				}
				trim(anillo); trim(especie); trim(pesoStr); trim(sexoStr); trim(fecha);
				double peso = 0.0;
				try { peso = std::stod(pesoStr); } catch (...) { peso = 0.0; }
				char sexo = sexoStr.empty() ? 'U' : sexoStr[0];
				NodoAve* nodo = new NodoAve(anillo, especie, peso, sexo, fecha);
				if (newHead == nullptr) {
					newHead = nodo;
					newTail = nodo;
				}
				else if (newTail != nullptr) {
					newTail->siguiente = nodo;
					newTail = nodo;
				}
				++contador;
			}
			cabeza = newHead;
			return contador;
		}
		catch (const std::exception& e) {
			std::cerr << "Error in cargarTodas: " << e.what() << std::endl;
			liberarListas(cabeza);
			return 0;
		}
		catch (...) {
			std::cerr << "Unknown error in cargarTodas" << std::endl;
			liberarListas(cabeza);
			return 0;
		}
	}
	int Bitacora::cargarValidas(NodoAve*& cabeza)
	{
		try {
			liberarListas(cabeza);
			validas_ = 0;
			descartadas_ = 0;
			std::ifstream ifs(ruta_);
			if (!ifs) return 0;
			std::string line;

			auto is_space = [](char ch) {
				return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f' || ch == '\v';
			};
			auto trim = [&](std::string &s) {
				size_t start = 0;
				while (start < s.size() && is_space(s[start])) ++start;
				if (start > 0) s.erase(0, start);
				while (!s.empty() && is_space(s.back())) s.pop_back();
			};
			NodoAve* newHead = nullptr;
			NodoAve* newTail = nullptr;
			while (std::getline(ifs, line)) {
				std::stringstream ss(line);
				std::string anillo, especie, pesoStr, sexoStr, fecha;
				if (!std::getline(ss, anillo, ';')) { ++descartadas_; continue; }
				if (!std::getline(ss, especie, ';')) { ++descartadas_; continue; }
				if (!std::getline(ss, pesoStr, ';')) { ++descartadas_; continue; }
				if (!std::getline(ss, sexoStr, ';')) { ++descartadas_; continue; }
				if (!std::getline(ss, fecha, ';')) {
					if (!std::getline(ss, fecha)) fecha = "";
				}
				trim(anillo); trim(especie); trim(pesoStr); trim(sexoStr); trim(fecha);
				double peso = 0.0;
				try { peso = std::stod(pesoStr); } catch (...) { peso = -1.0; }
				char sexo = sexoStr.empty() ? '\0' : sexoStr[0];


				if (anillo.empty() || especie.empty() || peso <= 0.0) {
					++descartadas_;
					continue;
				}

				char sUpper = sexo;
				if (sUpper >= 'a' && sUpper <= 'z') sUpper = static_cast<char>(sUpper - ('a' - 'A'));
				if (!(sUpper == 'M' || sUpper == 'H' || sUpper == 'X')) {
					++descartadas_;
					continue;
				}

				NodoAve* nodo = new NodoAve(anillo, especie, peso, sUpper, fecha);
				if (newHead == nullptr) { 
					newHead = nodo; 
					newTail = nodo; 
				}
				else if (newTail != nullptr) { 
					newTail->siguiente = nodo; 
					newTail = nodo; 
				}
				++validas_;
			}
			cabeza = newHead;
			return validas_;
		}
		catch (const std::exception& e) {
			std::cerr << "Error in cargarValidas: " << e.what() << std::endl;
			liberarListas(cabeza);
			validas_ = 0;
			descartadas_ = 0;
			return 0;
		}
		catch (...) {
			std::cerr << "Unknown error in cargarValidas" << std::endl;
			liberarListas(cabeza);
			validas_ = 0;
			descartadas_ = 0;
			return 0;
		}
	}
	int Bitacora::getValidas() const
	{
		return validas_;
	}
	int Bitacora::getDesacartadas() const
	{
		return descartadas_;
	}
	void Bitacora::liberarListas(NodoAve*& cabeza)
	{
		while (cabeza) {
			NodoAve* siguiente = cabeza->siguiente;
			delete cabeza;
			cabeza = siguiente;
		}
		cabeza = nullptr;
	}
}