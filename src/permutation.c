//
// Created by ksy on 03.09.2021.
// https://www.hackerrank.com/challenges/permutations-of-strings/problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int lexicographic_sort(const char* a, const char* b) {
  int aLen = strlen(a);
  int bLen = strlen(b);
  int index = 0;
  while (index<aLen && index<bLen){
    if (a[index]>b[index])
      return 1;
    else if (a[index]<b[index])
      return -1;
    index++;
  }
  if (aLen==bLen)
    return 0;
  if (index==aLen)
    return -1;
  if (index==bLen)
    return 1;

  return 0;
}

void swap_string(char** a, char** b){
  char* tmp = *a;
  *a = *b;
  *b = tmp;
}

int next_permutation(int n, char **s)
{
  /**
  * Complete this method
  * Return 0 when there is no next permutation and 1 otherwise
  * Modify array s to its next permutation
  */

  int index = n-1;
  while( index > 0 ){
    if (lexicographic_sort(s[index],s[index-1] ) > 0) break;
    --index;
  }
  // Permutation complete
  if (index==0) {
    return 0;
  }
  int l;
  for (l=n-1; (l>(index-1)) && (lexicographic_sort(s[l], s[index-1]) <= 0); --l){
  }
  swap_string(&s[l], &s[index-1]);

  for(int high= n-1, low=index ; high>low; --high, ++low){
    swap_string(&s[low], &s[high]);
  }
  return 1;
}

int permutationNarayanaAppCall(void){
  char **s;
  int n;
  scanf("%d", &n);
  s = calloc(n, sizeof(char*));
  for (int i = 0; i < n; i++)
  {
    s[i] = calloc(11, sizeof(char));
    scanf("%s", s[i]);
  }
  do
  {
    for (int i = 0; i < n; i++)
      printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
  } while (next_permutation(n, s));
  for (int i = 0; i < n; i++)
    free(s[i]);
  free(s);
  return 0;
}