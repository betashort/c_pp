//
//  main.cpp
//  pra2
//
//  Created by βshort on 2018/02/21.
//  Copyright © 2018年 sample-user. All rights reserved.
//

#include <iostream>
#include <stdio.h>
//クラスの定義
class MikanBox{
public:
  //メンバ関数
  void Add(int addmikan);
  void Del(int delmikan);
  void Empty();
  //メンバ関数をクラス内で定義
  int GetTotal(){
    return total;
  }
private:
  //メンバ変数
  int total;
};
//メンバ関数の定義
void MikanBox::Add(int addmikan){
  total += addmikan;
}
void MikanBox::Del(int delmikan){
  total -= delmikan;
  if(total < 0) Empty();
}
void MikanBox::Empty(){
  total = 0;
}

int main() {
  //オブジェクト生成
  MikanBox myMikanBox;
  //メンバ関数の呼び出し
  myMikanBox.Empty();
  myMikanBox.Add(9);
  myMikanBox.Del(2);
  printf("箱の中のみかん:%d個\n",myMikanBox.GetTotal());
  return 0;
}
