#串

#定位操作,即朴素模式匹配：若主串S中存在与串T值相同的子串，
#则返回它在主串S中第一次出现的位置,否则函数值为0.
int Index(SString S,SString T){
  int n = StrLength(S), m = StrLength(T);
  int i = 1;
  while(i <= n - m + 1){  #最多需要循环判断n-m+1次
    SubString(sub,S,i,m);   #从S中取出子串，从位置i开始长度为m的子串
    if(StrCompare(sub,T) != 0)  #如果不匹配
      i++;
    else
      return i;
  }
  return 0;
}

int Index(SString S,SString T){
  int i = 1,j = 1;
  while(i <= S.length && j <= T.Length){
    if(S[i] == T[j]){
      i++;
      j++;
    }
    else {  #指针后退重新匹配
      i = i - j + 2; 
      j = 1;
    }
  }
  if(j > T.length)
    return i - T.length;
  else
    return 0;
}
