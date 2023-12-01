#include <fstream>
#include <iostream>
#define NMAX 200
using namespace std;
int e[NMAX+1];
int main()
{
	ifstream f("grupe1.in");
	ofstream g("grupe1.out");
	int n, k, i;
	f >> n >> k;
	int uz[n+1];
	for (i = 1; i <= n; i++)
	{
		char c;
		f >> c;
		if (c == 'f') e[i] = 1;
		uz[i] = 1;
	}
	int nrmax, nrmin, fmax, fmin, bmax, bmin;
	nrmax = fmax = bmax = 0;
	nrmin = fmin = bmin = NMAX;
	for (i = 1; i <= k; i++)
	{
		int nr;
		f >> nr;
		if (nr > nrmax) nrmax = nr;
		if (nr < nrmin) nrmin = nr;
		int nrf=0, nrb=0;
		while (nr > 0)
		{
			int j;
			f >> j;
			uz[j] = 0;
			if (e[j] == 1) nrf++;
			else nrb++;
			nr--;
		}
		g << nrb << ' ' << nrf << '\n';
		if (nrf > fmax) fmax = nrf;
		if (nrf < fmin) fmin = nrf;
		if (nrb > bmax) bmax = nrb;
		if (nrb < bmin) bmin = nrb;
	}
	f.close();
	bool ok = 1;
	if (nrmax-nrmin > 1) ok = 0;
	if (fmax-fmin > 1) ok = 0;
	if (bmax-bmin > 1) ok = 0;
	if (ok)
		for (i = 1; i <= n; i++)
			if (uz[i])
			{
				ok = 0;
				break;
			}
	if (ok) g << "DA";
	else g << "NU";
	g.close();
	return 0;
}

