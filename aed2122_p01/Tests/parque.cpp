#include "parque.h"
#include <vector>

using namespace std;

//a)
ParqueEstacionamento::ParqueEstacionamento(unsigned lot, unsigned nMaxCli):
    lotacao(lot),
    numMaximoClientes(nMaxCli),
    vagas(lot) {}
unsigned ParqueEstacionamento::getNumLugares() const{
    return lotacao;
}
unsigned ParqueEstacionamento::getNumMaximoClientes() const{
    return numMaximoClientes;
}
//b)
int ParqueEstacionamento::posicaoCliente(const string & nome) const{
    for (int i = 0; i < clientes.size(); ++i) {
        if(clientes[i].nome==nome)
            return i;
    }
    return -1;
}
bool ParqueEstacionamento::adicionaCliente(const string & nome){
    if(clientes.size()>= numMaximoClientes)
        return false;
    else if(posicaoCliente(nome)==-1){
        InfoCartao cliente;
        cliente.nome=nome;
        cliente.presente= false;
        clientes.push_back(cliente);
        return true;
    }
    else return false;
}
//c)
bool ParqueEstacionamento::entrar(const string & nome){
    if(vagas==0 || posicaoCliente(nome)==-1 || clientes[posicaoCliente(nome)].presente)
        return false;
    else{
        clientes[posicaoCliente(nome)].presente= true;
        vagas--;
        return true;
    }
}
//d)
bool ParqueEstacionamento::retiraCliente(const string & nome){
    for (auto i = clientes.begin(); i != clientes.end(); ++i) {
        if((*i).nome==nome && !(*i).presente){
            clientes.erase(i);
            return true;
        }
    }
    return false;
}

bool ParqueEstacionamento::sair(const string & nome){
    int pos = posicaoCliente(nome);
    if(pos==-1 || !clientes[pos].presente)
        return false;
    else{
        clientes[pos].presente= false;
        vagas++;
        return true;
    }
}
//f)
unsigned ParqueEstacionamento::getNumLugaresOcupados() const{
    return lotacao-vagas;
}

unsigned ParqueEstacionamento::getNumClientesAtuais() const{
    return clientes.size();
}