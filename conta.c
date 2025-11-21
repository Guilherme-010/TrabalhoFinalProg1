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
    
    if(valor >= 0) { //Checa se é positivo
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

int aplicar_poupança(long long valor, long long* saldo_poupanca, long long* saldo_corrente){
    enum status situacao;
    
    if(valor >= 0) { // Transfere da corrente para a poupanca
        if(valor >= *saldo_corrente){
            *saldo_poupanca += valor;
            *saldo_corrente -= valor;
            situacao = 0;
        } else{
            situacao = 2;
        }
    } else {
        situacao = 1;
    }
    return situacao;
}

int resgatar_poupanca(long long valor, long long* saldo_poupanca, long long* saldo_corrente){
    enum status situacao;
    
    if(valor >= 0) { //Transfere da poupanca para a corrente
        if(valor >= *saldo_poupanca){
            *saldo_corrente += valor;
            *saldo_poupanca -= valor;
            situacao = 0;
        } else {
            situacao = 2;
        }
    } else {
        situacao = 1;
    }
}

void extrato_imprimir(enum TipoTransacao tp, char quando[20]) { //use for no main
    switch (tp) {
        case 0:
        printf("Tipo de Transação: DEPÓSITO\n");
        break;
        case 1:
        printf("Tipo de Transação: SAQUE\n");
        break;
        case 2:
        printf("Tipo de Transação: APLICAÇÃO NA POUPANÇA\n");
        break;
        case 3:
        printf("Tipo de Transação: RESGATE DA POUPANÇA\n");
        break;
        case 4:
        printf("Tipo de Transação: PIX\n");
        break;
        case 5:
        printf("Tipo de Transação: RENDIMENTO\n");
        break;
        case 6:
        printf("Tipo de Transação: RECEBER PIX\n");
        break;
    }
    printf("Tempo: %20s", quando);
}