#include <cfloat>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

class Point 
{ 
  public:
	  int x, y; 
}; 

double compareX(Point a, Point b);
double compareY(Point a, Point b);
double bruteForce(Point P[], int n);
double dist(Point p1, Point p2);

double points_dc (Point* P, int n)
{

  if (n <= 3)
  {
    // n = 1 -> Não é um conjunto válido, pois não pode ser dividido e não há distância a ser calculada
    // n = 2 -> Basta calcular a distância entre os dois pontos
    // n = 3 -> Não pode ser separado em dois conjuntos válidos (2/1 ou 1/2)
    return bruteForce(P, n);
  }

  sort(P, P + n, compareX); // Ordena os pontos de acordo com a coordenada x

  int mid = n / 2; // Ponto médio
 
  double d_left = points_dc(P, mid); // Distância mínima do lado esquerdo P[0..mid]
  double d_right = points_dc(P + mid, n - mid); // Distância mínima do lado direito P[mid+1..n]

  double d = min(d_left, d_right); // Distância mínima entre os dois conjuntos

  Point strip[n]; // Armazena os pontos que estão a uma distância horizontal máxima d da linha central
  int strip_size = 0;
  for (int i = 0; i < n; i++)
  {
    if (abs(P[i].x - P[mid].x) < d)
    {
      strip[strip_size] = P[i];
      strip_size++;
    }
  }


  // Ordena os pontos de acordo com a coordenada y
  sort(strip, strip + strip_size, compareY);

  // Verifica se existem pontos em lados opostos da linha central que estão a uma distância menor que d 
  for (int i = 0; i < strip_size; i++)
  {
    int k = 1;

    while (i + k < strip_size && strip[i + k].y - strip[i].y < d)
    {
      d = min(d, dist(strip[i], strip[i + k]));
      k++;
    }
  }


  return d;
}

int main()
{
  Point P[] = {{3, 4}, {6, 8}, {9, 12}, {12, 16}, {12, 10}, {3, 4}};

  int n = sizeof(P) / sizeof(P[0]);

  cout << "The smallest distance is " << points_dc(P, n) << endl;


  return 0;
}


double compareX(Point a, Point b) 
{ 
  return (a.x - b.x);
}

double compareY(Point a, Point b) 
{ 
  return (a.y - b.y);
}

double dist(Point p1, Point p2)
{
  return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}


double bruteForce(Point P[], int n)
{
  double min = DBL_MAX;
  for (int i = 0; i < n; ++i)
  {
    for (int j = i + 1; j < n; ++j)
    {
      if (dist(P[i], P[j]) < min)
      {
        min = dist(P[i], P[j]);
      }
    }
  }
  return min;
}
