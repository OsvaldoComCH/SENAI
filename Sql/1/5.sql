Create Database E;
Use E;

Create Table Loja
(
	IDLoja int Primary Key Auto_increment,
    Nome Varchar(50) Not NULL,
    Local Varchar(254) Not NULL
);

Create Table Caminhao
(
	IDCaminhao int Primary Key Auto_increment,
    Peso int Not NULL,
    Volume Float Not NULL,
    Capacidade int Not NULL
);

Create Table Viagem
(
	IDViagem int Primary Key Auto_increment,
    IDCaminhao int Not NULL,
    Foreign Key (IDCaminhao) References Caminhao(IDCaminhao)
);

Create Table LojaViagem
(
	IDLojaViagem int primary key auto_increment,
    Data DateTime Not NULL,
    IDLoja int,
    Foreign Key (IDLoja) References Loja(IDLoja),
    IDViagem int,
    Foreign Key (IDViagem) References Viagem(IDViagem)
);


Create Table Encomenda
(
	IDEncomenda int Primary Key Auto_increment,
    Peso Varchar(50) Not NULL,
    Destino int Not NULL,
    Foreign Key (Destino) References Loja(IDLoja)
);


Create Table EncomendaViagem
(
	IDEncomendaViagem int Primary Key Auto_increment,
	IDEncomenda int,
    Foreign Key (IDEncomenda) References Encomenda(IDEncomenda),
	IDViagem int,
    Foreign Key (IDViagem) References Viagem(IDViagem)
);