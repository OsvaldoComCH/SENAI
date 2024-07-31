Create Database Oficina;
Use Oficina;

Create Table Cliente
(
	IDCliente int Primary Key Auto_increment,
    Nome Varchar(50) Not NULL,
    Telefone Varchar(12) Not NULL,
    Endereco Varchar(254) Not NULL
);

Create Table Veiculo
(
	IDVeiculo int Primary Key Auto_increment,
    IDCliente int Not NULL,
	Foreign Key (IDCliente) references Cliente(IDCliente),
    Marca Varchar(20) Not NULL,
    Modelo Varchar(30) Not NULL,
    Ano int Not NULL,
    Placa Varchar(8) Not NULL
);

Create Table Ordem
(
	IDOrdem int Primary Key Auto_increment,
    IDCliente int Not NULL,
	Foreign Key (IDCliente) references Cliente(IDCliente),
    IDVeiculo int Not NULL,
	Foreign Key (IDVeiculo) references Veiculo(IDVeiculo),
    DataEntrada Date Not NULL,
    DataSaida Date Not NULL,
    Status Varchar(20) Not NULL,
    Observacao Varchar(254) Not NULL
);

Create Table Servico
(
	IDServico int Primary Key Auto_increment,
    Nome Varchar(50) Not NULL,
    Preco Float Not NULL
);

Create Table ItemServico
(
	IDItemServico int Primary Key Auto_increment,
    IDOrdem int Not NULL,
	Foreign Key (IDOrdem) references Ordem(IDOrdem),
    IDServico int Not NULL,
	Foreign Key (IDServico) references Servico(IDServico),
    Quantidade Float Not NULL
);