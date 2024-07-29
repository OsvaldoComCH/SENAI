Create Database B;
Use B;
Create Table Cliente
(
	IDCliente int primary key auto_increment,
    Nome Varchar(60) Not NULL,
    RG Varchar(20) Not NULL,
    Endereco Varchar(254) Not NULL,
    Telefone Varchar(12) Not NULL
);
Create Table Produto
(
	IDProduto int Primary Key auto_increment,
    Tipo Varchar(20) Not NULL,
    Nome Varchar(60) Not NULL,
    Preco Float Not NULL,
    Estoque int Not NULL
);
Create Table Compra
(
	IDCompra int primary key auto_increment,
    Data DateTime Not NULL,
    Valor Float Not NULL,
    IDCliente int,
    Foreign Key (IDCliente) References Cliente(IDCliente)
);
Create Table Venda
(
	IDVenda int Primary Key Auto_increment,
    IDCliente int,
    Foreign Key (IDCliente) References Cliente(IDCliente),
    IDProduto int,
    Foreign Key (IDProduto) References Produto(IDProduto)
);