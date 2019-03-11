#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>
using namespace std;

void vif(double v[3][10]) {
  /*
   cout << "配列の確認"　<< endl;
   
   for (int i = 0; i < 3; i++){
   for (int t = 0; t < 10; t++){
   v[i][t];
   cout << v[i][t] << " ";
   
   }
   }
   
   */
  /*
   変数管理
  */
  //平均
  vector <double> mean;
  //分散
  vector <double> var;
  //標準偏差
  vector <double> stdv;
  //vif
  vector<double> vif_1d;
  double sum = 0;
  
  double xx = 0, yy = 0, xy = 0, cc = 0;
  
  //vectorに変換
  vector <double> v_1d;
  for (int i = 0; i < 3; i++){
    for (int t = 0; t < 10; t++){
      v_1d.push_back(v[i][t]);
    }
  }
  
  cout << "vecotr変換の確認" << endl;
  
  //確認
  for (int i = 0; i < v_1d.size(); i++){
    cout << v_1d[i] << ",";
    if ( i % 10 == 9){
      cout << endl;
    }
  }
  
  //平均を求める
  cout << "平均を求める" << endl;
  int t = 0;
  for (int i = 0; i < v_1d.size(); i++){
    sum += v_1d[i];
    if ( i % 10 == 9){
      //cout << sum << endl;
      mean.push_back(sum/10);
      cout << t << ":" << mean[t] << endl;
      t++;
      sum = 0;
    }
  }
  cout << "相関係数とVIFを求める" << endl;
  
  int c = int(v_1d.size()/10);
   for (int i = 0; i < c-1 ; i++) {
     for (int k = i + 1; k < c; k++) {
       for (int l = 0; l < 10; l++) {
         //分散
         xx += pow(v_1d[i*9 + l] - mean[i], 2);
         //分散
         yy += pow(v_1d[k*9 + l] - mean[k], 2);
         //共分散
         xy += (v_1d[i*9 + l] - mean[i]) * (v_1d[k*9 + l] - mean[k]);
         
       }
       cout << mean[i] << endl << mean[k] << endl;
       
       //分散
       //cout << "分散" << xx/10 << endl;
       
       xx = sqrt(xx);
       yy = sqrt(yy);
       cc = pow(xy / (xx*yy), 2);
       
       cout << "xx：" << xx << endl;
       cout << "yy：" << yy << endl;
       cout << "cc：" << xy / (xx*yy) << endl;
       
       cout << "i：" << i << "k：" << k << endl;
       //VIF統計量
       vif_1d.push_back(1 / (1 - cc));
       printf("vif：%f\n", vif_1d[i]);
       xx = 0;
       yy = 0;
       xy = 0;
       
     }
   }
}


void test(int x[]){
  for (int i = 0; i < 10; i++){
    x[i] += 1;
  }
}

int main(void){
  // Your code here!
  /*
  double v[3][10];
  for (int i = 0; i < 3; i++){
    for (int t = 0; t < 10; t++){
      v[i][t] = (rand()%10) ;
    }
  }
  vif(v);
  */
  int x[] = {};
  for (int i=0; i < 10; i++){
    x[i] = i;
    cout << x[i] << " ";
  }
  cout << endl;
  
  test(x);
  
  for (int i=0; i < 10; i++){
    x[i] = i;
    cout << x[i] << " ";
  }
  
  
  
  return 0;
}
