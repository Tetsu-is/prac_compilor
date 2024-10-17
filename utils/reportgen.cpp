#include <stdio.h>
#include <string>
using namespace std;

int main(void) {
  int p_num;
  char p_alpha[10];
  printf("Generate Report from Template!\n");

  printf("Enter p_num p_alpha: ");
  scanf("%d %s", &p_num, p_alpha);

  // get count of tasks
  printf("Enter the count of tasks: ");
  int p_count;
  scanf("%d", &p_count);

  FILE *fp;
  char fn[50];
  snprintf(fn, sizeof(fn), "R%d%s.txt", p_num, p_alpha);

  char path[50];
  snprintf(path, sizeof(path), "repo/%s", fn);
  fp = fopen(path, "w");

  // err handling
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  // get current time
  time_t now = time(0);
  tm *local_time = localtime(&now);
  int m = local_time->tm_mon + 1;
  int date = local_time->tm_mday;
  string dt = to_string(m) + "/" + to_string(date);

  string templateStr = "##コンパイラ実習 37022497 石本哲郎\n"
                       "##日付 " +
                       dt +
                       "\n"
                       "\n";

  // Add tasks
  for (int i = 1; i <= p_count; i++) {
    templateStr += "##課題 " + to_string(i) +
                   "\n\n"
                   "#課題内容\n\n"
                   "#結果\n\n"
                   "#感想\n\n\n";
  }

  fprintf(fp, "%s", templateStr.c_str());

  fclose(fp);
  return 0;
}