Create Database C;
Use C;

Create Table Paciente
(
	IDPaciente int Primary Key Auto_increment,
    Nome Varchar(50) Not NULL,
    Endereco Varchar(254) Not NULL,
    DataNasc Date Not NULL,
    Registro int Not NULL
);

Create Table Medico
(
	IDMedico int Primary Key Auto_increment,
    Nome Varchar(50) Not NULL,
    Especialidade Varchar(30) Not NULL,
    CRM int Not NULL
);

Create Table Consulta
(
	IDConsulta int primary key auto_increment,
    Data DateTime Not NULL,
    IDMedico int,
    Foreign Key (IDMedico) References Medico(IDMedico),
    IDPaciente int,
    Foreign Key (IDPaciente) References Paciente(IDPaciente)
);

Create Table Medicamento
(
	IDMedicamento int Primary Key Auto_increment,
    Nome Varchar(50) Not NULL
);

Create Table Receita
(
	IDReceita int primary key auto_increment,
    IDMedicamento int,
    Foreign Key (IDMedicamento) References Medicamento(IDMedicamento),
    IDConsulta int,
    Foreign Key (IDConsulta) References Consulta(IDConsulta),
    Observacao Varchar(100) Not NULL
);

Create Table Exame
(
	IDExame int Primary Key Auto_increment,
    Serial int Not NULL,
    Descricao Varchar(100) Not NULL
);

Create Table Requisicao
(
	IDRequisicao int Primary Key Auto_increment,
	IDConsulta int,
    Foreign Key (IDConsulta) References Consulta(IDConsulta),
	IDExame int,
    Foreign Key (IDExame) References Exame(IDExame),
    Data DateTime Not NULL
);