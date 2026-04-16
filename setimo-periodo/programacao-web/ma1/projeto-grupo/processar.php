<?php
$nome = $_POST['nome'] ?? '';
$ra = $_POST['ra'] ?? '';
$email = $_POST['email'] ?? '';
$curso = $_POST['curso'] ?? '';
$periodo = $_POST['periodo'] ?? '';
$autorizacao = isset($_POST['autorizacao']);

if (empty($nome) || empty($ra) || empty($email) || empty($curso) || empty($periodo) || !$autorizacao) {
    echo "Erro: Campos obrigatórios vazios. <a href='index.html'>Voltar</a>";
}

$nome = htmlspecialchars($nome);
$ra = htmlspecialchars($ra);
$email = htmlspecialchars($email);
$curso = htmlspecialchars($curso);
?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <title>Confirmação</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <header><h1>Dados Cadastrados</h1></header>
    <main>
        <table>
            <tr><td><strong>Nome:</strong></td><td><?= $nome ?></td></tr>
            <tr><td><strong>RA:</strong></td><td><?= $ra ?></td></tr>
            <tr><td><strong>E-mail:</strong></td><td><?= $email ?></td></tr>
            <tr><td><strong>Curso:</strong></td><td><?= $curso ?></td></tr>
            <tr><td><strong>Semestre:</strong></td><td><?= $periodo ?>º</td></tr>
        </table>
        <p><a href="index.html">Novo Cadastro</a></p>
    </main>
</body>
</html>