#define _CRT_SECURE_NO_WARNINGS
#include "Function.h"

using namespace std;

// Главное меню
void Function()
{
	int n;
	system("cls");
	do
	{
		cout << " Список операций:" << endl
			<< " 1. Вычисление определенного интеграла на отрезке " << endl
			<< " 2. Построение графика функции " << endl
			<< " 3. Поиск корня Y = 0 на отрезке " << endl
			<< " 4. Поиск экстремумов на отрезке " << endl
			<< " 0. Выход " << endl
			<< endl << " Выберите операцию : ";
		cin >> n;

		if ((n < 0) or (n > 4)) { cout << "  Введено неверное значение" << endl << endl; }

		system("cls");
		cin.get();
		switch (n)
		{
		case 1: {DefIntegral(); break; }
		case 2: {Graph(); break; }
		case 3: {Root(); break; }
		case 4: {Extreme(); break; }
		default: break;
		}
	} while (n != 0);
}


//Функции на ввод параметров

// Полином степени N 
void Polinomial(double* Pol, int &N)
{
	for (int i = 0; i <= N; i++)
	{
		cout << " a" << i << " = ";
		cin >> Pol[i];
	}
	system("cls");
}

// Степенная 
void DegreeF(double& a, double& b, double& c)
{
	cout << " Введите параметр a: ";
	cin >> a;
	cout << " Введите параметр b: ";
	cin >> b;
	cout << " Введите параметр c: ";
	cin >> c;
	system("cls");
}

// Показательная 
void IndexF(double& a, double& b, double& c, double& d)
{
	cout << " Введите параметр a: ";
	cin >> a;
	do
	{
		cout << " Введите параметр b(b>0, b!=1): ";
		cin >> b;
		if ((b <= 0) or (b == 1)) { cout << " Введено неверное значение" << endl; }
	} while ((b <= 0) or (b == 1));
	cout << " Введите параметр c: ";
	cin >> c;
	cout << " Введите параметр d: ";
	cin >> d;
	system("cls");
}

// Логарифмическая 
// Зависимость области значений X от введенного параметра b
void LogF(double& a, double& b, double& c)
{
	cout << " Введите параметр a: ";
	cin >> a;
	do
	{
		cout << " Введите параметр b (b!=0): ";
		cin >> b;
		if (b == 0) { cout << " Введено неверное значение " << endl; }
	} while (b == 0);
	cout << " Введите параметр c: ";
	cin >> c;
	system("cls");
}

// Синусоида 
void SinF(double& a, double& b, double& c, double& d)
{
	cout << " Введите параметр a: ";
	cin >> a;
	cout << " Введите параметр b: ";
	cin >> b;
	cout << " Введите параметр c: ";
	cin >> c;
	cout << " Введите параметр d: ";
	cin >> d;
	system("cls");
}

// Косинусоида 
void CosF(double& a, double& b, double& c, double& d)
{
	cout << " Введите параметр a: ";
	cin >> a;
	cout << " Введите параметр b: ";
	cin >> b;
	cout << " Введите параметр c: ";
	cin >> c;
	cout << " Введите параметр d: ";
	cin >> d;
	system("cls");
}


// Функции на вычисление значений функции

// Значение функции полинома
double ResPolinomialF(const double* Pol, const int& N, const double& x)
{
	double y = 0;
	int k=0;
	for (int i = 0; i <= N; i++)
	{
		y += Pol[i] * pow(x, k);
		k++;
	}
	return y;
}

// Значение степенной функции
double ResDegreeF(const double& a, const double& b, const double& c, const double& x)
{
	double y = 0;
	y = a * pow(x, b) + c;
	return y;
}

// Значение показательной функции
double ResIndexF(const double& a, const double& b, const double& c, const double& d, const double& x)
{
	double y = 0;
	y = a * pow(b, (c*x)) + d;
	return y;
}

// Значение логарифмической функции
double ResLogF(const double& a, const double& b, const double& c, const double& x)
{
	double y = 0;
	y = a * log(b * x) + c;
	return y;
}

// Значение функции синуса
double ResSinF(const double& a, const double& b, const double& c, const double& d, const double& x)
{
	double y = 0;
	y = a * sin(b * x + c) + d;
	return y;
}

// Значение функции косинуса
double ResCosF(const double& a, const double& b, const double& c, const double& d, const double& x)
{
	double y = 0;
	y = a * cos(b * x + c) + d;
	return y;
}


// Операции калькулятора функций

// Вычисление определенного интеграла на отрезке 
void DefIntegral()
{
	double a = 0, b = 0, c = 0, d = 0;
	int Func, N;
	double* Pol = NULL;
	do
	{
		cout << " Построение графика функции " << endl
			<< " ==============================" << endl;
		cout << " Список обрабатываемых функций:" << endl
			<< " 1. Полином степени N: a0 + a1*x + a2*x^2 +...+ aN*x^n " << endl
			<< " 2. Степенная: a*x^b + c " << endl
			<< " 3. Показательная: a*b^(c*x) + d " << endl
			<< " 4. Логарифмическая: a*ln(b*x) + c " << endl
			<< " 5. Синусоида: a*sin(b*x + c) + d " << endl
			<< " 6. Косинусоида: a*cos(b*x + c) + d " << endl
			<< " 0. Выход " << endl
			<< endl << " Выберите функцию: ";
		cin >> Func;

		if ((Func < 0) or (Func > 6)) { cout << " Введено неверное значение" << endl << endl; }

		cin.get();
		switch (Func)
		{
		case 1:
		{
			system("cls");
			cout << " Полином степени N" << endl
				<< " ===================" << endl;
			do
			{
				cout << " Введите степень полинома (N>=0): ";
				cin >> N;
				if (N < 0) { cout << " Введено неверное значение " << endl; }
			} while (N < 0);
			Pol = (double*)malloc(sizeof(double) * (N + 1));
			Polinomial(Pol, N);
			break;
		}
		case 2:
		{
			system("cls");
			cout << " Степенная функция" << endl
				<< " ====================" << endl;
			DegreeF(a, b, c);
			break;
		}
		case 3:
		{
			system("cls");
			cout << " Показательная функция" << endl
				<< " =======================" << endl;
			IndexF(a, b, c, d);
			break;
		}
		case 4:
		{
			system("cls");
			cout << " Логарифмическая функция " << endl
				<< " ==========================" << endl;
			LogF(a, b, c);
			break;
		}
		case 5:
		{
			system("cls");
			cout << " Синусоида" << endl
				<< " ===========" << endl;
			SinF(a, b, c, d);
			break;
		}
		case 6:
		{
			system("cls");
			cout << " Косинусоида" << endl
				<< " =============" << endl;
			CosF(a, b, c, d);
			break;
		}
		case 0: { system("cls"); break; }
		default: break;
		}
	} while (Func < 0);

	// Само вычисление интеграла
	if (Func != 0)
	{
		double Start, End, Step;

		do
		{
			cout << " Введите начало отрезка: ";
			cin >> Start;
			cout << " Введите конец отрезка: ";
			cin >> End;
			cout << " Введите размерность шага: ";
			cin >> Step;
			if ((End < Start) or (Step <= 0)) { cout << " Введены неверные значения" << endl; }
		} while ((End < Start) or (Step <= 0));

	}
}

// Построение графика функции
void Graph()
{
	double a = 0, b = 0, c = 0, d = 0;
	int Func, N;
	double* Pol = NULL;
	do
	{
		cout << " Построение графика функции " << endl
			<< " ==============================" << endl;
		cout << " Список обрабатываемых функций:" << endl
			<< " 1. Полином степени N: a0 + a1*x + a2*x^2 +...+ aN*x^n " << endl
			<< " 2. Степенная: a*x^b + c " << endl
			<< " 3. Показательная: a*b^(c*x) + d " << endl
			<< " 4. Логарифмическая: a*ln(b*x) + c " << endl
			<< " 5. Синусоида: a*sin(b*x + c) + d " << endl
			<< " 6. Косинусоида: a*cos(b*x + c) + d " << endl
			<< " 0. Выход " << endl
			<< endl << " Выберите функцию: ";
		cin >> Func;

		if ((Func < 0) or (Func > 6)) { cout << " Введено неверное значение" << endl << endl; }

		cin.get();
		switch (Func)
		{
		case 1:
		{
			system("cls");
			cout << " Полином степени N" << endl
				<< " ===================" << endl;
			do
			{
				cout << " Введите степень полинома (N>=0): ";
				cin >> N;
				if (N < 0) { cout << " Введено неверное значение " << endl; }
			} while (N < 0);
			Pol = (double*)malloc(sizeof(double) * (N+1));
			Polinomial(Pol, N);
			break;
		}
		case 2:
		{
			system("cls");
			cout << " Степенная функция" << endl
				<< " ====================" << endl;
			DegreeF(a, b, c);
			break;
		}
		case 3:
		{
			system("cls");
			cout << " Показательная функция" << endl
				<< " =======================" << endl;
			IndexF(a, b, c, d);
			break;
		}
		case 4:
		{
			system("cls");
			cout << " Логарифмическая функция " << endl
				<< " ==========================" << endl;
			LogF(a, b, c);
			break;
		}
		case 5:
		{
			system("cls");
			cout << " Синусоида" << endl
				<< " ===========" << endl;
			SinF(a, b, c, d);
			break;
		}
		case 6:
		{
			system("cls");
			cout << " Косинусоида" << endl
				<< " =============" << endl;
			CosF(a, b, c, d);
			break;
		}
		case 0: { system("cls"); break; }
		default: break;
		}
	} while (Func < 0);

	// Построение графика функции
	if (Func != 0)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			printf("SDL не смог запуститься! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			double Start, End;

			do
			{
				cout << " Введите начало отрезка: ";
				cin >> Start;
				cout << " Введите конец отрезка: ";
				cin >> End;
				if (End < Start) { cout << " Введены неверные значения" << endl; }
			} while (End < Start);

			SDL_Window* window = NULL;
			SDL_Renderer* renderer = NULL;
			window = SDL_CreateWindow(u8"Боблак", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (window == NULL)
			{
				printf("Окно не может быть создано! SDL_Error: %s\n", SDL_GetError());
			}
			else
			{
				// фон
				renderer = SDL_CreateRenderer(window, -1, 0);
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
				SDL_RenderClear(renderer);

				// система координат
				int x0, y0, Normal = 0;
				double Step = 0;

				Step = (double)SCREEN_WIDTH / double(End - Start + 2);
				Normal = int(double(End + Start) / 2);

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

				x0 = int((double)SCREEN_WIDTH * double(1.0 / 2)) - Normal * Step;
				y0 = int((double)SCREEN_HEIGHT * double(1.0 / 2));

				for (int i = 0; i <= SCREEN_WIDTH; i++)
				{
					for (int j = 0; j <= SCREEN_HEIGHT; j++)
					{
						if ((i == x0) or (j == y0)) { SDL_RenderDrawPoint(renderer, i, j); }
					}
				}

				SDL_Rect rectY;
				rectY.w = 6;
				rectY.h = 1;

				SDL_Rect rectX;
				rectX.w = 1;
				rectX.h = 6;

				SDL_Rect rectC;
				rectC.x = x0 - 3;
				rectC.y = y0 - 3;
				rectC.w = 6;
				rectC.h = 6;
				SDL_RenderFillRect(renderer, &rectC);

				int k = 0;
				for (int t = 0; t <= End; t++)
				{
					rectX.x = x0 + Step * k;
					rectX.y = y0 - 3;
					SDL_RenderFillRect(renderer, &rectX);
					k++;
				}
				k = 0;
				for (int t = 0; t >= Start; t--)
				{
					rectX.x = x0 + Step * k;
					rectX.y = y0 - 3;
					SDL_RenderFillRect(renderer, &rectX);
					k--;
				}

				k = -1;
				for (int t = int((double)SCREEN_WIDTH * double(1.0 / 2) / (double)Step); t < int((double)SCREEN_WIDTH / (double)Step); t++)
				{
					rectY.y = y0 + Step * k;
					rectY.x = x0 - 3;
					SDL_RenderFillRect(renderer, &rectY);
					k++;
				}
				k = -1;
				for (int t = int((double)SCREEN_WIDTH * double(1.0 / 2) / (double)Step); t >= 0; t--)
				{
					rectY.y = y0 + Step * k;
					rectY.x = x0 - 3;
					SDL_RenderFillRect(renderer, &rectY);
					k--;
				}

				// график
				SDL_Point Point[SCREEN_WIDTH];

				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
				double lock;
				for (int t = int((double)SCREEN_WIDTH * double(1.0 / 2)); t < SCREEN_WIDTH; t++)
				{
					Point[t].x = t;
					switch (Func)
					{
					case 1:
					{
						Point[t].y = int((double)y0 - ResPolinomialF(Pol, N, double(Point[t].x - x0) / (double)Step) * Step);
						break;
					}
					case 2:
					{
						Point[t].y = int((double)y0 - ResDegreeF(a, b, c, double(Point[t].x - x0) / (double)Step) * Step);
						break;
					}
					case 3:
					{
						Point[t].y = int((double)y0 - ResIndexF(a, b, c, d, double(Point[t].x - x0) / (double)Step) * Step);
						break;
					}
					case 4:
					{
						if (double(x0 - Point[t].x) == 0) { Point[t].y = SCREEN_HEIGHT * 2; }
						else
						{
							Point[t].y = int((double)y0 - ResLogF(a, b, c, double(Point[t].x - x0) / (double)Step) * Step);
						}
						break;
					}
					case 5:
					{
						Point[t].y = int((double)y0 - ResSinF(a, b, c, d, double(Point[t].x - x0) / (double)Step) * Step);
						break;
					}
					case 6:
					{
						Point[t].y = int((double)y0 - ResCosF(a, b, c, d, double(Point[t].x - x0) / (double)Step) * Step);
						break;
					}
					default: break;
					}
					lock = double(Point[t].x - x0) / (double)Step;
					if (lock > End)
					{
						break;
					}
				}
				for (int t = int((double)SCREEN_WIDTH * double(1.0 / 2)); t >= 0; t--)
				{
					Point[t].x = int(t);
					switch (Func)
					{
					case 1:
					{
						Point[t].y = int((double)y0 - ResPolinomialF(Pol, N, double(Point[t].x - x0) / (double)Step) * Step);
						break;
					}
					case 2:
					{
						Point[t].y = int((double)y0 - ResDegreeF(a, b, c, double(Point[t].x - x0) / (double)Step) * Step);
						break;
					}
					case 3:
					{
						Point[t].y = int((double)y0 - ResIndexF(a, b, c, d, double(Point[t].x - x0) / (double)Step) * Step);
						break;
					}
					case 4:
					{
						if (double(x0 - Point[t].x) == 0) { Point[t].y = SCREEN_HEIGHT * 2; }
						else
						{
							Point[t].y = int((double)y0 - ResLogF(a, b, c, double(Point[t].x - x0) / (double)Step) * Step); 
						}
						break;
					}
					case 5:
					{
						Point[t].y = int((double)y0 - ResSinF(a, b, c, d, double(Point[t].x - x0) / (double)Step) * Step);
						break;
					}
					case 6:
					{
						Point[t].y = int((double)y0 - ResCosF(a, b, c, d, double(Point[t].x - x0) / (double)Step) * Step);
						break;
					}
					default: break;
					}
					lock = double(Point[t].x - x0) / (double)Step;
					if (lock < Start)
					{
						break;
					}
				}
				SDL_RenderDrawLines(renderer, Point, SCREEN_WIDTH);

				free(Pol);

				SDL_RenderPresent(renderer);
				SDL_Delay(10000);
			}

			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_Quit();
		}
		system("cls");
	}
}

// Поиск корня Y = 0 на отрезке
void Root()
{
	double a = 0, b = 0, c = 0, d = 0, y;
	int Func, N;
	double* Pol = NULL;
	do
	{
		cout << " Построение графика функции " << endl
			<< " ==============================" << endl;
		cout << " Список обрабатываемых функций:" << endl
			<< " 1. Полином степени N: a0 + a1*x + a2*x^2 +...+ aN*x^n " << endl
			<< " 2. Степенная: a*x^b + c " << endl
			<< " 3. Показательная: a*b^(c*x) + d " << endl
			<< " 4. Логарифмическая: a*ln(b*x) + c " << endl
			<< " 5. Синусоида: a*sin(b*x + c) + d " << endl
			<< " 6. Косинусоида: a*cos(b*x + c) + d " << endl
			<< " 0. Выход " << endl
			<< endl << " Выберите функцию: ";
		cin >> Func;

		if ((Func < 0) or (Func > 6)) { cout << " Введено неверное значение" << endl << endl; }

		cin.get();
		switch (Func)
		{
		case 1:
		{
			system("cls");
			cout << " Полином степени N" << endl
				<< " ===================" << endl;
			do
			{
				cout << " Введите степень полинома (N>=0): ";
				cin >> N;
				if (N < 0) { cout << " Введено неверное значение " << endl; }
			} while (N < 0);
			Pol = (double*)malloc(sizeof(double) * (N + 1));
			Polinomial(Pol, N);
			break;
		}
		case 2:
		{
			system("cls");
			cout << " Степенная функция" << endl
				<< " ====================" << endl;
			DegreeF(a, b, c);
			break;
		}
		case 3:
		{
			system("cls");
			cout << " Показательная функция" << endl
				<< " =======================" << endl;
			IndexF(a, b, c, d);
			break;
		}
		case 4:
		{
			system("cls");
			cout << " Логарифмическая функция " << endl
				<< " ==========================" << endl;
			LogF(a, b, c);
			break;
		}
		case 5:
		{
			system("cls");
			cout << " Синусоида" << endl
				<< " ===========" << endl;
			SinF(a, b, c, d);
			break;
		}
		case 6:
		{
			system("cls");
			cout << " Косинусоида" << endl
				<< " =============" << endl;
			CosF(a, b, c, d);
			break;
		}
		case 0: { system("cls"); break; }
		default: break;
		}
	} while (Func < 0);

	// Поиск корня
	if (Func != 0)
	{
		double Start, End, Step;

		do
		{
			cout << " Введите начало отрезка: ";
			cin >> Start;
			cout << " Введите конец отрезка: ";
			cin >> End;
			cout << " Введите погрешность: ";
			cin >> Step;
			if ((End < Start) or (Step <= 0)) { cout << " Введены неверные значения" << endl; }
		} while ((End < Start) or (Step <= 0));

		int k = 0;
		double* Root = (double*)malloc(sizeof(double) * (k + 1));
		for (double x = Start; x <= End; x += Step)
		{
			switch (Func)
			{
			case 1:
			{
				y = ResPolinomialF(Pol, N, x);
				break;
			}
			case 2:
			{
				y = ResDegreeF(a, b, c, x);
				break;
			}
			case 3:
			{
				y = ResIndexF(a, b, c, d, x);
				break;
			}
			case 4:
			{
				y = ResLogF(a, b, c, x);
				break;
			}
			case 5:
			{
				y = ResSinF(a, b, c, d, x);
				break;
			}
			case 6:
			{
				y = ResCosF(a, b, c, d, x);
				break;
			}
			default: break;
			}
			if (y == 0) { Root[k] = x; k++; Root = (double*)realloc(Root, sizeof(double) * (k + 1)); }
		}

		if (k == 0) { cout << " Для Y = 0 корней нет" << endl; }
		else
		{
			cout << " Корни уравнения для Y = 0: " << endl;
			for (int l = 0; l < k; l++)
			{
				cout << " " << l + 1 << ". " << Root[l] << endl;
			}
		}
		free(Pol);
		free(Root);
		cout << endl << " Для продолжения нажмите любую клавишу: " << endl << " ";
		_getch();
		system("cls");
	}
}

// Поиск экстремумов на отрезке 
void Extreme()
{
	double a = 0, b = 0, c = 0, d = 0, y1, y2, y3;
	int Func, N;
	double* Pol = NULL;
	do
	{
		cout << " Построение графика функции " << endl
			<< " ==============================" << endl;
		cout << " Список обрабатываемых функций:" << endl
			<< " 1. Полином степени N: a0 + a1*x + a2*x^2 +...+ aN*x^n " << endl
			<< " 2. Степенная: a*x^b + c " << endl
			<< " 3. Показательная: a*b^(c*x) + d " << endl
			<< " 4. Логарифмическая: a*ln(b*x) + c " << endl
			<< " 5. Синусоида: a*sin(b*x + c) + d " << endl
			<< " 6. Косинусоида: a*cos(b*x + c) + d " << endl
			<< " 0. Выход " << endl
			<< endl << " Выберите функцию: ";
		cin >> Func;

		if ((Func < 0) or (Func > 6)) { cout << " Введено неверное значение" << endl << endl; }

		cin.get();
		switch (Func)
		{
		case 1:
		{
			system("cls");
			cout << " Полином степени N" << endl
				<< " ===================" << endl;
			do
			{
				cout << " Введите степень полинома (N>=0): ";
				cin >> N;
				if (N < 0) { cout << " Введено неверное значение " << endl; }
			} while (N < 0);
			Pol = (double*)malloc(sizeof(double) * (N + 1));
			Polinomial(Pol, N);
			break;
		}
		case 2:
		{
			system("cls");
			cout << " Степенная функция" << endl
				<< " ====================" << endl;
			DegreeF(a, b, c);
			break;
		}
		case 3:
		{
			system("cls");
			cout << " Показательная функция" << endl
				<< " =======================" << endl;
			IndexF(a, b, c, d);
			break;
		}
		case 4:
		{
			system("cls");
			cout << " Логарифмическая функция " << endl
				<< " ==========================" << endl;
			LogF(a, b, c);
			break;
		}
		case 5:
		{
			system("cls");
			cout << " Синусоида" << endl
				<< " ===========" << endl;
			SinF(a, b, c, d);
			break;
		}
		case 6:
		{
			system("cls");
			cout << " Косинусоида" << endl
				<< " =============" << endl;
			CosF(a, b, c, d);
			break;
		}
		case 0: { system("cls"); break; }
		default: break;
		}
	} while (Func < 0);

	// Поиск экстремумов
	if (Func != 0)
	{
		double Start, End, Step;

		do
		{
			cout << " Введите начало отрезка: ";
			cin >> Start;
			cout << " Введите конец отрезка: ";
			cin >> End;
			cout << " Введите погрешность: ";
			cin >> Step;
			if ((End < Start) or (Step <= 0)) { cout << " Введены неверные значения" << endl; }
		} while ((End < Start) or (Step <= 0));

		int k = 0, t = 0;
		double* Root1 = (double*)malloc(sizeof(double) * (k + 1));
		double* Root2 = (double*)malloc(sizeof(double) * (t + 1));
		for (double x = Start + Step; x <= End - Step; x += Step)
		{
			switch (Func)
			{
			case 1:
			{
				y1 = ResPolinomialF(Pol, N, x - Step);
				y2 = ResPolinomialF(Pol, N, x);
				y3 = ResPolinomialF(Pol, N, x + Step);
				break;
			}
			case 2:
			{
				y1 = ResDegreeF(a, b, c, x - Step);
				y2 = ResDegreeF(a, b, c, x);
				y3 = ResDegreeF(a, b, c, x + Step);
				break;
			}
			case 3:
			{
				y1 = ResIndexF(a, b, c, d, x - Step);
				y2 = ResIndexF(a, b, c, d, x);
				y3 = ResIndexF(a, b, c, d, x + Step);
				break;
			}
			case 4:
			{
				y1 = ResLogF(a, b, c, x - Step);
				y2 = ResLogF(a, b, c, x);
				y3 = ResLogF(a, b, c, x + Step);
				break;
			}
			case 5:
			{
				y1 = ResSinF(a, b, c, d, x - Step);
				y1 = ResSinF(a, b, c, d, x);
				y1 = ResSinF(a, b, c, d, x + Step);
				break;
			}
			case 6:
			{
				y1 = ResCosF(a, b, c, d, x - Step);
				y2 = ResCosF(a, b, c, d, x);
				y3 = ResCosF(a, b, c, d, x + Step);
				break;
			}
			default: break;
			}
			if ((y1 < y2) and (y3 < y2))
			{
				Root1[k] = x; k++; Root1 = (double*)realloc(Root1, sizeof(double) * (k + 1));
			}
			if ((y1 > y2) and (y3 > y2))
			{
				Root2[t] = x; t++; Root2 = (double*)realloc(Root2, sizeof(double) * (t + 1));
			}

		}

		if (k == 0) { cout << " Точек максимума у функции нет " << endl; }
		else
		{
			cout << " Точки максимума: " << endl;
			for (int l = 0; l < k; l++)
			{
				cout << " " << l + 1 << ". " << Root1[l] << endl;
			}
			cout << endl;
		}
		if (t == 0) { cout << " Точек минимума у функции нет " << endl; }
		else
		{
			cout << " Точки минимума: " << endl;
			for (int l = 0; l < t; l++)
			{
				cout << " " << l + 1 << ". " << Root2[l] << endl;
			}
		}

		free(Pol);
		free(Root1);
		free(Root2);
		cout << endl << " Для продолжения нажмите любую клавишу: " << endl << " ";
		_getch();
		system("cls");
	}
}