Create Database D;
Use D;

Create Table Professor
(
	IDProfessor int Primary Key Auto_increment,
    Nome Varchar(50) Not NULL,
    Telefone Varchar(12) Not NULL
);

Create Table Aula
(
	IDAula int Primary Key Auto_increment,
    Modalidade Varchar(50) Not NULL,
    Dificuldade Varchar(20) Not NULL,
    IDProfessor int Not NULL,
    Foreign Key (IDProfessor) References Professor(IDProfessor)
);

Create Table Sala
(
	IDSala int Primary Key Auto_increment,
    Capacidade int Not NULL
);

Create Table SalaAula
(
	IDSalaAula int primary key auto_increment,
    Data DateTime Not NULL,
    IDSala int,
    Foreign Key (IDSala) References Sala(IDSala),
    IDAula int,
    Foreign Key (IDAula) References Aula(IDAula)
);


Create Table Aluno
(
	IDAluno int Primary Key Auto_increment,
    Nome Varchar(50) Not NULL,
    DataNasc Date Not NULL,
    Sexo char(1) Not NULL,
    Instituicao Varchar(50) Not NULL,
    Telefone Varchar(12) Not NULL
);


Create Table AlunoAula
(
	IDAlunoAula int Primary Key Auto_increment,
	IDAluno int,
    Foreign Key (IDAluno) References Aluno(IDAluno),
	IDAula int,
    Foreign Key (IDAula) References Aula(IDAula)
);