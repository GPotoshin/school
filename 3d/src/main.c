#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include <math.h>

#include "../include/grooph.h"

const double FI = 1.6180339887498948482045868;

typedef struct {
    double x, y;
} vec2;

typedef struct {
    double x, y, z;
} vec3;

typedef struct {
    double a11, a12, a13,
           a21, a22, a23,
           a31, a32, a33;
 } matrix;

double tetrahedron[12] = {1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, 1};
double octahedron[18] = {1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1};
double cube[24] = {1, 1, 1, 1, 1, -1, 1, -1, 1, 1, -1, -1, -1, 1, 1, -1, 1, -1, -1, -1, 1, -1, -1, -1};
double icosahedron[36] = {0, 1, FI, 0, 1, -FI, 0, -1, FI, 0, -1, -FI, 1, FI, 0, 1, -FI, 0, -1, FI, 0, -1, -FI, 0, FI, 0, 1, FI, 0, -1, -FI, 0, 1, -FI, 0, -1};
double dodecahedron[60] = {1, 1, 1, 1, 1, -1, 1, -1, 1, 1, -1, -1, -1, 1, 1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 0, 1/FI, FI, 0, 1/FI, -FI, 0, -1/FI, FI, 0, -1/FI, -FI, 1/FI, FI, 0, 1/FI, -FI, 0, -1/FI, FI, 0, -1/FI, -FI, 0, FI, 0, 1/FI, FI, 0, -1/FI, -FI, 0, 1/FI, -FI, 0, -1/FI};

int lines_tetr[12] = {0, 1, 0, 2, 0, 3, 1, 2, 2, 3, 3, 1};
int lines_octa[24] = {0, 2, 0, 3, 0, 4, 0, 5, 1, 2, 1, 3, 1, 4, 1, 5, 2, 4, 4, 3, 3, 5, 5, 2};
int lines_cube[24] = {0, 1, 0, 2, 0, 4, 7, 6, 7, 5, 7, 3, 1, 3, 3, 2, 2, 6, 6, 4, 4, 5, 5, 1};
int lines_icos[60] = {0, 6, 0, 4, 0, 8, 0, 2, 0, 10, 2, 8, 8, 4, 4, 6, 6, 10, 10, 2, 2, 7, 2, 5, 8, 5, 8, 9, 4, 9, 4, 1, 6, 1, 6, 11, 10, 11, 10, 7, 1, 9, 9, 5, 5, 7, 7, 11, 11, 1, 3, 1, 3, 9, 3, 5, 3, 7, 3, 11};
int lines_dode[60] = {1, 9, 9, 5, 5, 14, 14, 12, 12, 1, 1, 17, 9, 11, 5, 19, 14, 4, 12, 0, 0, 16, 16, 17, 17, 3, 3, 11, 11, 7, 7, 19, 19, 18, 18, 4, 4, 8, 8, 0, 8, 10, 18, 6, 7, 15, 3, 13, 16, 2, 2, 10, 10, 6, 6, 15, 15, 13, 13, 2};

void printMatrix (matrix m) {
    printf ("|%lf, %lf, %lf|\n|%lf, %lf, %lf|\n|%lf, %lf, %lf|\n",
        m.a11, m.a12, m.a13, m.a21, m.a22, m.a23, m.a31, m.a32, m.a33);
}

double determinant (matrix m) {
    return  m.a11*(m.a22*m.a33-m.a23*m.a32) - m.a12*(m.a21*m.a33-m.a23*m.a31) + m.a13*(m.a21*m.a32-m.a22*m.a31);
}

matrix multMatrix (matrix m1, matrix m2) {
    return (matrix) {m1.a11*m2.a11+m1.a12*m2.a21+m1.a13*m2.a31, m1.a11*m2.a12+m1.a12*m2.a22+m1.a13*m2.a32, m1.a11*m2.a13+m1.a12*m2.a23+m1.a13*m2.a33,
                       m1.a21*m2.a11+m1.a22*m2.a21+m1.a23*m2.a31, m1.a21*m2.a12+m1.a22*m2.a22+m1.a23*m2.a32, m1.a21*m2.a13+m1.a22*m2.a23+m1.a23*m2.a33,
                       m1.a31*m2.a11+m1.a32*m2.a21+m1.a33*m2.a31, m1.a31*m2.a12+m1.a32*m2.a22+m1.a33*m2.a32, m1.a31*m2.a13+m1.a32*m2.a23+m1.a33*m2.a33};
}

vec3 matrixXvector (matrix m, vec3 v) {
    return (vec3) {v.x*m.a11+v.y*m.a12+v.z*m.a13, v.x*m.a21+v.y*m.a22+v.z*m.a23, v.x*m.a31+v.y*m.a32+v.z*m.a33};
}

matrix genRotMatrix (double a1, double a2, double a3) {
    matrix m1 = {1, 0, 0, 0, cos(a1), -sin(a1), 0, sin(a1), cos(a1)};
    matrix m2 = {cos(a2), 0, sin(a2), 0, 1, 0, -sin(a2), 0, cos(a2)};
    matrix m3 = {cos(a3), -sin(a3), 0, sin(a3), cos(a3), 0, 0, 0, 1};

    return multMatrix (multMatrix (m1, m2), m3);
}

void drawSolid (double * vertices, int len_vertices, int * lines, int len_lines, const char * fname) {
    FILE *fp = fopen(fname, "wb");
    if (!fp) {
        printf ("can't open %s file\n", fname);
        return;
    }

    GrImg * img = grInitDefaultImg(GR_PNG);
    if (!img) {
        printf ("can't allocate memory ofr img\n");
        return;
    }

    if (grSetSize (img, 1440, 900)) {
		printf ("GRSetSize: Can't allocate memory!\n");
		return;
	}

    GrColor color = {0x2e, 0x34, 0x40};
    grFullBackground (img, color);

    color = (GrColor){0xec, 0xef, 0xf4};

    matrix rot = genRotMatrix(1, 2, 0.3);

    for (int i = 0; i < len_vertices; i += 3) {
        vec3 vec = {vertices[i], vertices[i+1], vertices[i+2]};
        vec = matrixXvector (rot, vec);
        vertices[i] = vec.x;
        vertices[i+1] = vec.y;
        vertices[i+2] = vec.z+7;
    }


    for (int i = 0; i < len_lines; i += 2) {
        vec3 s3 = {vertices[lines[i]*3], vertices[lines[i]*3+1], vertices[lines[i]*3+2]};
        vec3 e3 = {vertices[lines[i+1]*3], vertices[lines[i+1]*3+1], vertices[lines[i+1]*3+2]};

        int p1[2] = {720.+1000.*s3.x/s3.z, 450.+1000.*s3.y/s3.z};
        int p2[2] = {720.+1000.*e3.x/e3.z, 450.+1000.*e3.y/e3.z};
        GrColor c = {color.red*23./(s3.z*s3.z+e3.z*e3.z), color.green*23./(s3.z*s3.z+e3.z*e3.z), color.blue*23./(s3.z*s3.z+e3.z*e3.z)};
        grDrawLine (img, p1, p2, c, 2);
    }
    grWriteImg (img, fp);
    grDestroyImg (img);
    fclose (fp);
}

int main () {
    drawSolid (tetrahedron, 12, lines_tetr, 12, "tetr.png");
    drawSolid (octahedron, 18, lines_octa, 24, "octa.png");
    drawSolid (cube, 24, lines_cube, 24, "cube.png");
    drawSolid (icosahedron, 36, lines_icos, 60, "icos.png");
    drawSolid (dodecahedron, 60, lines_dode, 60, "dode.png");
    return 0;
}