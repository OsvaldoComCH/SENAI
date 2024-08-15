CREATE DATABASE db_loja_eletronicos;

USE db_loja_eletronicos;

-- Tabela `produtos`
CREATE TABLE produtos (
    id_produto INT PRIMARY KEY AUTO_INCREMENT,
    nome_produto VARCHAR(100) NOT NULL,
    categoria VARCHAR(50) NOT NULL,
    preco DECIMAL(10, 2) NOT NULL,
    quantidade_estoque INT NOT NULL,
    preco_medio DECIMAL(10, 2) NOT NULL default 0.00,
    valor_total_vendas decimal(10, 2) Not NULL default 0.00
);

-- Tabela `clientes`
CREATE TABLE clientes (
    id_cliente INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    telefone VARCHAR(20) DEFAULT NULL,
    valor_total_compras DECIMAL(10, 2) DEFAULT 0.00
);

-- Tabela `vendas`
CREATE TABLE vendas (
    id_venda INT PRIMARY KEY AUTO_INCREMENT,
    id_produto INT NOT NULL,
    id_cliente INT NOT NULL,
    data_venda DATE NOT NULL,
    quantidade INT NOT NULL,
    valor_total DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (id_produto) REFERENCES produtos(id_produto),
    FOREIGN KEY (id_cliente) REFERENCES clientes(id_cliente)
);

-- Tabela `promocoes`
CREATE TABLE promocoes (
    id_promocao INT PRIMARY KEY AUTO_INCREMENT,
    nome_promocao VARCHAR(100) NOT NULL,
    data_inicio DATE NOT NULL,
    data_fim DATE NOT NULL,
    desconto DECIMAL(5, 2) NOT NULL
);

-- Tabela `notificacoes`
CREATE TABLE notificacoes (
    id_notificacao INT PRIMARY KEY AUTO_INCREMENT,
    mensagem TEXT NOT NULL,
    data_notificacao DATETIME DEFAULT CURRENT_TIMESTAMP
);

/*
1.Registrar uma nova venda e atualizar o valor total de compras por cliente.
2. Trigger para aplicar desconto de promoção em vendas
3.Atualizar o preço médio de um produto após uma nova venda.
4.Rastrear alterações no estoque de produtos e registrar uma notificação dentro de um log.
5.Registrar novos clientes e gerar uma mensagem de usuário cadastrado dentro de um log.
6.Monitorar vendas de produtos em promoção e registrar uma notificação.
7.Registrar produtos em falta no estoque e gerar uma notificação.
8.Atualizar o valor total de vendas de um produto após uma nova venda.
9.Rastrear alterações no valor de produtos e registrar uma notificação.
*/
Delimiter //
Create Trigger TR_UpdateVendas
After Insert
On vendas
For Each Row
Begin
	Update clientes set valor_total_compras = valor_total_compras + New.valor_total where id_cliente = New.id_cliente;
End;
//Delimiter ;

Delimiter //
Create Trigger TR_Desconto
before Insert
On vendas
For Each Row
Begin
	update New set valor_total = valor_total * (1 -((Select desconto from promocoes where New.Data_Venda between Data_inicio and Data_fim limit 1) / 100));
End;
//Delimiter ;

Delimiter //
Create Trigger TR_PrecoMedio
after Insert
On vendas
For Each Row
Begin
	Update produtos set preco_medio = (select Avg(sum(venda_total*quantidade)) from vendas) where id_produto = New.id_produto;
End;
//Delimiter ;

Delimiter //
Create Trigger TR_LogEstoque
after Update
On produtos
For Each Row
Begin
	if(New.Quantidade_estoque != Old.Quantidade_estoque) then
		Insert into notificacoes (mensagem) Values (concat("Estoque do Produto ", New.id_produto, " alterado para ", New.quantidade_estoque));
    end if;
End;
//Delimiter ;

Delimiter //
Create Trigger TR_LogCliente
after Insert
On clientes
For Each Row
Begin
	Insert into notificacoes (mensagem) Values (concat("Cliente ", New.id_cliente, " Cadastrado"));
End;
//Delimiter ;

Delimiter //
Create Trigger TR_LogDesconto
after Insert
On vendas
For Each Row
Begin
	If((Select desconto from promocoes where New.Data_Venda between Data_inicio and Data_fim limit 1)) Then
		Insert into notificacoes (mensagem) Values (concat("Venda ", New.id_venda, " realizada em promocao"));
	End If;
End;
//Delimiter ;

Delimiter //
Create Trigger TR_LogFaltaEstoque
after Update
On produtos
For Each Row
Begin
	If(new.quantidade_estoque <= 0) Then
		Insert into notificacoes (mensagem) Values (concat("Produto ", New.id_produto, " está sem estoque"));
	End If;
End;
//Delimiter ;

Delimiter //
Create Trigger TR_TotalVendas
after Insert
On vendas
For Each Row
Begin
	Update produtos set valor_total_vendas = valor_total_vendas + New.valor_total where id_produto = New.id_produto;
End;
//Delimiter ;

Delimiter //
Create Trigger TR_LogPreco
after Update
On produtos
For Each Row
Begin
	if(New.preco != Old.preco) then
		Insert into notificacoes (mensagem) Values concat(("Preço do Produto ", New.id_produto, " alterado para ", New.preco));
    end if;
End;
//Delimiter ;