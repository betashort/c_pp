//
//  sample-3_1.cpp
//  average_filter
//
//  Created by sawano on 2016/04/01.
//  Copyright © 2016年 AIT. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>


#define VAL_MAX (256) //輝度値の要素数
#define N (2) //フィルタサイズを決定する数値．フィルタサイズは(2N+1)になる

//木の画像
#define FILENAME "/Users/betashort/Pictures/naruna_kankore.png"

int main(int argc, const char * argv[]) {
  int u, v, x, y; //ループ用変数
  
  //画像の入力 (グレースケール)
  cv::Mat src_img = cv::imread(FILENAME, 0);
  if (src_img.empty()) { //入力失敗の場合
    return (-1);
  }
  //平均化フィルタ
  cv::Mat h = cv::Mat_<double>(2*N+1, 2*N+1);
  for (v=0; v<2*N+1; v++) {
    for (u=0; u<2*N+1; u++) {
      h.at<double>(v, u) = 1.0 / (double)((2*N+1)*(2*N+1));
    }
  }
  
  //出力画像のメモリ確保
  cv::Mat dst_img = cv::Mat(src_img.size(), CV_8U, 1);
  
  
  //画像の走査
  for (y=0; y<src_img.rows; y++) {
    for (x=0; x<src_img.cols; x++) {
      //画像端の処理
      if (x<N || y<N || x==src_img.cols-1-N || y==src_img.rows-1-N) {
        dst_img.at<unsigned char>(y, x) = 0; //画像端は計算不可
        continue;
      }
      double tmp = 0;
      //フィルタのループ
      for (v=-N; v<=N; v++) {
        for (u=-N; u<=N; u++) {
          tmp += (h.at<double>(v+N, u+N) * (double)src_img.at<unsigned char>(v+y, u+x));
        }
      }
      //負もしくは輝度値の最大値を超えない処理
      if ((int)tmp < 0){               tmp = 0;
      }else if ((int)tmp >= VAL_MAX) {  tmp = VAL_MAX - 1;}
      
      dst_img.at<unsigned char>(y, x) = (unsigned char)tmp;
    }
  }
  
  //画像の表示
  cv::imshow("input", src_img);
  cv::imshow("output", dst_img);
  cv::waitKey(); //キー入力待ち
  cv::imwrite("ave.jpg", dst_img); //保存
  
  return 0;
}

