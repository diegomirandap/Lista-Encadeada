//Diego Miranda: 2210996
//Eric Goulart: 2110878

struct pacientes;
typedef struct pacientes Pacientes;

Pacientes* lst_cria (void);

Pacientes* lst_insere_ordenado (Pacientes* lst, int cor, int* ord);

Pacientes* lst_remove (Pacientes* lst,int ord);

void lst_imprime (Pacientes* lst);

void lst_conta_cor (Pacientes* lst);

void lst_libera (Pacientes*lst);




