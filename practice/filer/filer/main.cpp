//
//  main.cpp
//  filer
//
//  Created by βshort on 2018/05/23.
//  Copyright © 2018 sample-user. All rights reserved.
//
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<fstream>

using namespace std;

FILE *fp;

void vif(double x[][1000]) {
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
      
      xx = 0; yy = 0; xy = 0;
      
    }
  }
}

int main(int argc, const char * argv[]) {
  
  double x[3][1000] = {};
  fp =fopen("vif.csv", "rb");
  
  if (fp == NULL) {
    printf("ファイルオープンエラー");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < 1000; i++) {
    fscanf(fp, "%lf,%lf,%lf", &x[0][i],& x[1][i],& x[2][i]);
    printf("%lf,%lf,%lf,\n", x[0][i], x[1][i], x[2][i]);
  }
  fclose(fp);
  
  return 0;
  /*
   if ((error = fopen_s(&fp, "", "w")) == NULL) {
   printf("ファイルオープンエラー");
   exit(EXIT_FAILURE);
   }
   fprintf(fp, "HelloWorld¥n");
   fclose(fp);
   */
}
