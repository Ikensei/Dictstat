/*pelvic sorcery*/

#ifndef DICTSTAT_H
#define DICTSTAT_H

int dictstat(FILE* dict_file,FILE* data_file);
void readDict(FILE* dict_file);
void scanData(FILE* data_file);

#endif
