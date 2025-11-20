#include <stdio.h>
#include "conta.h"

int depositar(long long valor, long long* saldo) { //para a conta corrente
    enum status situacao;
    
    if(valor > 0) { //Checando se é positivo
        *saldo += valor;
        situacao = OK; //Retorna 0
    } else {
        situacao = ERRO_VALOR_INVALIDO; //Retorna 1
    }
    return situacao;
}

int sacar(long long valor, long long* saldo) { //para a conta corrente
    enum status situacao;
    
    if(valor > 0) { //Checa se é positivo
        if((*saldo - valor) > 0) { //Checa se há saldo
            *saldo -= valor;
            situacao = OK; //Retorna 0
        } else {
            situacao = ERRO_SALDO_INSUFICIENTE; //Retorna 2
        }
    } else {
        situacao = ERRO_VALOR_INVALIDO; //Retorna 1
    }
    
    return situacao;
}

void saldo_corrente(long long* saldo){
    printf("O seu saldo é: %d", *saldo);
}



// conta_corrente(void){
    
}