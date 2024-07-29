Create Database A;
Use A;
Create Table Soldado
(
	IDSoldado int primary key auto_increment,
    Nome Varchar(60) Not NULL,
    RM Varchar(20) Not NULL
);
Create Table Arma
(
	IDArma int primary key auto_increment,
    Serial int Not NULL,
    Tipo Varchar(20) Not NULL,
    Calibre Varchar(10) Not NULL,
    IDSoldado int,
    Foreign Key (IDSoldado) References Soldado(IDSoldado)
);
Create Table Limpeza
(
	IDLimpeza int Primary Key Auto_increment,
    IDSoldado int,
    Foreign Key (IDSoldado) References Soldado(IDSoldado),
    IDArma int,
    Foreign Key (IDArma) References Arma(IDArma)
);
Create Table Municao
(
	IDMunicao int Primary Key auto_increment,
    Tipo Varchar(20) Not NULL,
    Calibre Varchar(10) Not NULL
);
Create Table ArmaMunicao
(
	IDArmaMunicao int Primary Key Auto_increment,
    IDMunicao int,
    Foreign Key (IDMunicao) References Municao(IDMunicao),
    IDArma int,
    Foreign Key (IDArma) References Arma(IDArma)
);