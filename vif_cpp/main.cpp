#include<stdio.h>
#include<math.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>

#pragma warning(disable : 4996);

using namespace std;

void vif(double x[3][1000]) {
	double mean1 = 0;
	double mean[3] = {};
	double xx = 0, yy = 0, xy = 0, cc = 0;
	//平均を求める
	for (int i = 0; i < 3; i++) {
		for (int l = 0; l < 1000; l++) {
			mean1 += x[i][l];
		}
		mean[i] = mean1 / 1000;
		mean1 = 0;
	}

	for (int i = 0; i<2; i++) {
		for (int k = i + 1; k < 3; k++) {
			for (int l = 0; l < 1000; l++) {
				//分散
				xx += pow(x[i][l] - mean[i], 2);
				//分散
				yy += pow(x[k][l] - mean[k], 2);
				//共分散
				xy += (x[i][l] - mean[i]) * (x[k][l] - mean[k]);
			}
			//標準偏差
			xx = sqrt(xx);
			yy = sqrt(yy);
			cc = pow(xy / (xx*yy), 2);

			//VIF統計量
			printf("%f\n", 1 / (1 - cc));

			xx = 0, yy = 0, xy = 0;

		}
	}
}

void main(void) {
	FILE *fp;
	char *fname = "vif.csv";
	int ret;
	int i = 0;
	char buf[3][10];
	double data[3][1000] = {};

	fp = fopen(fname, "r");
	if (fp == NULL) {
		printf("%sファイルが開けません\n", fname);
		exit(EXIT_FAILURE);
	}

	fscanf(fp, "%s,%s,%s", buf[0], buf[1], buf[2]);

	while ((ret = fscanf(fp, "%lf,%lf,%lf", &data[0][i], &data[1][i], &data[2][i])) != EOF) {
		//printf("%lf %lf %lf\n", data[i][0], data[i][1], data[i][2]);
		i++;
	}
	vif(data);
	printf("\n");
	fclose(fp);

	system("pause");
}
