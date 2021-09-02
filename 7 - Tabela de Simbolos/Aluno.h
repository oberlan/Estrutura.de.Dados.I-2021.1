#ifndef __ALUNO_H_
#define __ALUNO_H_

typedef struct aluno Aluno;
typedef int TipoChave;

Aluno *criaAluno(TipoChave, char *);

TipoChave getChave(Aluno *);

char *getNome(Aluno *);

void setChave(Aluno *, TipoChave);

void setNome(Aluno *, char *);


#endif