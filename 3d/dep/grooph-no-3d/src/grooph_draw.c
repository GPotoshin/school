#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <math.h>

#include "grooph_defs.h"
#include "grooph_core.h"
#include "grooph_draw.h"
#include "tools/grizmos.h"

static const int ** array_copy;

int grFullBackground (GrImg *img, GrColor color) {
	int retval = -1;
	if (!img->rows)
		goto _bailout;

	retval = -2;
	if (img->filetype == GR_PNG) {
		for (int j = 0; j < img->height; j++) {
			if (!img->rows[j])
				goto _bailout;
			for (int i = 0; i < img->width; i++) {
				GrBytep bp = img->rows[j] + i*3;
				bp[0] = color.red;
				bp[1] = color.green;
				bp[2] = color.blue;
			}
		}
	}

	retval = 0;
_bailout:
	return retval;
}


int grPutDot (GrImg *img, int p[2], GrColor color, int w) {
	int retval = -1;
	if (!img->rows)
		goto _bailout;

	retval = -2;
	if (img->filetype == GR_PNG) {
		for (int j = p[1] - w; j <= p[1] + w; j++) {
			if (!img->rows[j])
				goto _bailout;

			for (int i = p[0] - w; i <= p[0] + w; i++) {
				if (j < img->height && i < img->width &&
						((i-p[0])*(i-p[0]) + (j-p[1])*(j-p[1]) < w*w)) {
					GrBytep bp = img->rows[j] + i*3;
					if (bp[0]+color.red*1.5*w / (1.5*w + hypot (i-p[0], j-p[1])) < 256 &&
						bp[1]+color.green*1.5*w / (1.5*w + hypot (i-p[0], j-p[1])) < 256 &&
						bp[2]+color.blue*1.5*w / (1.5*w + hypot (i-p[0], j-p[1])) < 256)
					{
						bp[0] = bp[0]+color.red*1.5*w / (1.5*w + hypot (i-p[0], j-p[1]));
						bp[1] = bp[1]+color.green*1.5*w / (1.5*w + hypot (i-p[0], j-p[1]));
						bp[2] = bp[2]+color.blue*1.5*w / (1.5*w + hypot (i-p[0], j-p[1]));
					}
					else {
						bp[0] = color.red*1.5*w / (1.5*w + hypot (i-p[0], j-p[1]));
						bp[1] = color.green*1.5*w / (1.5*w + hypot (i-p[0], j-p[1]));
						bp[2] = color.blue*1.5*w / (1.5*w + hypot (i-p[0], j-p[1]));
					}
				}
			}
		}
	}

	retval = 0;
_bailout:
	return retval;
}


int grDrawLine (GrImg *img, int a[2], int b[2], GrColor color, int w) {
	int p1[2] = {a[0], a[1]};
	int p2[2] = {b[0], b[1]};

	int retval = -1;
	int p[2];
	if (p1[1] == p2[1]) {
		p[1] = p1[1];
		color.red /= 2;
		color.green /= 2;
		color.blue /= 2;
		for (p[0] = fmin (p2[0], p1[0]); p[0] <= fmax (p2[0], p1[0]); p[0]++) {
			grPutDot (img, p, color, w);
		}
	}
	if (p1[0] == p2[0]) {
		p[0] = p1[0];
		color.red /= 2;
		color.green /= 2;
		color.blue /= 2;
		for (p[1] = fmin (p2[1], p1[1]); p[1] <= fmax (p2[1], p1[1]); p[1]++) {
			grPutDot (img, p, color, w);
		}
	}

	if (p2[0] < p1[0]) {
		p1[1] += p2[1];
		p2[1] = p1[1] - p2[1];
		p1[1] -= p2[1];
		p1[0] += p2[0];
		p2[0] = p1[0] - p2[0];
		p1[0] -= p2[0];
	}

	p[0] = p1[0];
	p[1] = p1[1];
	double k = (double)(p2[1] - p1[1]) / (p2[0] - p1[0]);
	double m = 0.5*(p1[1] - k*p1[0] + p2[1] - k*p2[0]);

// Normalisation of colors depending on slope
// g(+-1) = 1
// g(0) = 0.5
// lim x->inf g(x) = 0.5
	double g = 0.6894 / ((1.1517*k + 1)*(1.1517*k + 1) + 1) +
		0.6894 / ((1.1517*k - 1)*(1.1517*k - 1) + 1) -
		0.6894 / (1.1517*1.1517*k*k + 1) + 0.5;
	color.red *= g;
	color.green *= g;
	color.blue *= g;

	if (k*k < 1) {
		if (k > 0) {
			while (p[0] <= p2[0]) {
				grPutDot (img, p, color, w);
				p[0]++;
				if (p[1] < k*p[0] + m) {
					p[1]++;
				}
			}
		}
		else {
			while (p[0] <= p2[0]) {
				grPutDot (img, p, color, w);
				p[0]++;
				if (p[1] > k*p[0] + m) {
					p[1]--;
				}
			}
		}
	}
	else {
		if (k > 0) {
			while (p[1] <= p2[1]) {
				grPutDot (img, p, color, w);
				p[1]++;
				if (p[0] < (p[1] - m) / k) {
					p[0]++;
				}
			}
		}
		else {
			while (p[1] >= p2[1]) {
				grPutDot (img, p, color, w);
				p[1]--;
				if (p[0] < (p[1] - m) / k) {
					p[0]++;
				}
			}
		}
	}

	retval = 0;
_bailout:
	return retval;
}

int grDrawCircle (GrImg *img, int p[2], int r, GrColor color, int w) {
	int v[2];
	double dt = 1.4 / r;
	for (double t = 0; t < 2 * M_PI; t += dt) {
		v[0] = p[0] + r*cos(t);
		v[1] = p[1] + r*sin(t);
		grPutDot (img, v, color, w);
	}
	return 0;
}

static int compare_y (const void *a, const void *b) {
	const int *ia = a;
	const int *ib = b;

	if ((array_copy[*ia])[1] > (array_copy[*ib])[1])
		return 1;
	else if ((array_copy[*ia])[1] < (array_copy[*ib])[1])
		return -1;
	return 0;
}

static int compare_line_x (const void *a, const void *b) {
	const int *ia = a;
	const int *ib = b;

	if ((array_copy[ia[0]])[0] > (array_copy[ib[0]])[0] || 
		array_copy[ia[1]][0] > array_copy[ib[1]][0])
		return 1;
	else if ((array_copy[ia[0]])[0] < (array_copy[ib[0]])[0] ||
			(array_copy[ia[1]])[0] < (array_copy[ib[1]])[0])
		return -1;
	return 0;
}

// fuck % operator: why -1%3 = -1???
static inline int modulo (int n, int base) {
	int ans = n%base;
	if (ans < 0)
		ans += base;
	return ans;
}

int grDrawPolygon (GrImg *img, const int **p, const int n, GrColorScheme *scheme) {
	array_copy = p;
	int retval = -1;
	int *a = malloc (n*sizeof(int));
	if (!a) {
		GR_LOG_ERROR("grDrawPolygon", "can't allocate a");
		goto _bailout;
	}
	
	retval = -2;

	for (int i = 0; i < n; i++)
		a[i] = i;

// compare function depends on array_copy
	qsort (a, n, sizeof(int), &compare_y);

//	printf ("!a:\n");
//	for (int i = 0; i < n; i++)
//		printf ("%d: (%d, %d)\n", i, (p[a[i]])[0], (p[a[i]])[1]);
//	putchar ('\n');

// polygon is devided into horizontal trapeziums
// side is reprezented by two points
// and top is counted with i, while (i+1) is bottom
// area between sides is colored
#define BUF_DELTA 16
	int line_buf_size = BUF_DELTA;
	int line_count = 0;
	int *line = malloc (line_buf_size*sizeof(int));
	if (!line) {
		GR_LOG_ERROR("grDrawPolygon", "can't allocate line");
		goto _bailout;
	}

	retval = -3;

	for (int i = 0; i < n;) {
		if ((p[a[i]])[1] == (p[a[n-1]])[1]) break;

		for (int j = 0; j < line_count; j += 2) {
			if ((p[line[j+1]])[1] <= (p[a[i]])[1]) {
				for (int k = j+2; k < line_count; k++) {
					line[k-2] = line[k];
				}
				line_count -= 2;
				j -= 2;
			}
		}
		{
			line_buf_size = (line_count / BUF_DELTA + 1) * BUF_DELTA;
			void *p = realloc (line, line_buf_size*sizeof(int));
			if (!p) {
				GR_LOG_ERROR("grDrawPolygon", "can't reallocate line(1)");
				goto _bailout;
			}
		}
		int j;
		for (j = i; (p[a[i]])[1] == (p[a[j]])[1] && j < n; j++) {
			if ((p[ (a[j]+1)%n ])[1] > (p[a[i]])[1]) {
				if (line_count == line_buf_size) {
					line_buf_size += BUF_DELTA;
					void *p = realloc (line, line_buf_size*sizeof(int));
					if (!p) {
						GR_LOG_ERROR("grDrawPolygon", "can't reallocate line(2)");
						goto _bailout;
					}
					line = p;
				}
				line[line_count] = a[j];
				line[line_count+1] = (a[j]+1)%n;
				line_count += 2;
			}
			if ((p[modulo(a[j]-1, n)])[1] > (p[a[i]])[1]) {
				if (line_count == line_buf_size) {
					line_buf_size += BUF_DELTA;
					void *p = realloc (line, line_buf_size*sizeof(int));
					if (!p) {
						GR_LOG_ERROR("grDrawPolygon", "can't reallocate line(3)");
						goto _bailout;
					}
					line = p;
				}
				line[line_count] = a[j];
				line[line_count+1] = modulo (a[j]-1, n);
				line_count += 2;
			}
		}
#undef BUF_DELTA
		qsort (line, line_count/2, 2*sizeof(int), &compare_line_x);
//		printf ("!lines %d (i = %d):\n", (p[a[i]])[1], i);
//		for (int l = 0; l < line_count; l += 2)
//			printf ("(%d, %d) -> (%d, %d)\n", (p[line[l]])[0], (p[line[l]])[1], (p[line[l+1]])[0], (p[line[l+1]])[1]);
//		putchar ('\n');

		for (int l = 0; l < line_count; l += 4) {
			double c1 = (double)((p[line[l+1]])[0] - (p[line[l]])[0]) / 
				((p[line[l+1]][1]) - (p[line[l]])[1]);
			double d1 = (double)(p[line[l]])[0] - c1*(p[line[l]])[1];

			double c2 = (double)((p[line[l+3]])[0] - (p[line[l+2]])[0]) / 
				((p[line[l+3]])[1] - (p[line[l+2]])[1]);
			double d2 = (double)(p[line[l+2]])[0] - c2*(p[line[l+2]])[1];

			for (int k = (p[a[i]])[1]; k < (p[a[j]])[1] && k < img->height; k++) {
				GrByte *bp = img->rows[k];
				for (int m = c1*k + d1; m <= c2*k + d2 && m < img->width; m++) {
					bp[m*3] = 50;
					bp[m*3+1] = 55;
					bp[m*3+2] = 55;
				}
			}
		}
		i = j;
	}
// last line
	if ((p[line[1]])[1] < img->height) {
		GrByte *bp = img->rows[(p[line[1]])[1]];
		for (int l = 0; l < line_count; l += 4) {
			for (int k = (p[line[l+1]])[0]; k <= (p[line[l+3]])[0] && k < img->width; k++) {
				bp[k*3] = 50;
				bp[k*3+1] = 55;
				bp[k*3+2] = 55;
			}
		}
	}
	retval = 0;
_bailout:

	if (a) free (a);
	if (line) free (line);

	return retval;
}
