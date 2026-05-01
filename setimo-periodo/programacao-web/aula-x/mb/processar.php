<?php

$titulo = $_POST['titulo'] ?? '';
$nome = $_POST['nome'] ?? '';
$email = $_POST['email'] ?? '';

$erros = [];

if (empty($titulo)) {
    $erros[] = "Título é obrigatório.";
}

if (empty($nome) || strlen($nome) < 3) {
    $erros[] = "Nome inválido.";
}

if (empty($email) || strpos($email, '@') === false) {
    $erros[] = "E-mail inválido.";
}

if (count($erros) > 0) {
    echo "<h3>Erros:</h3>";
    foreach ($erros as $erro) {
        echo "<p style='color:red;'>$erro</p>";
    }
    echo "<a href='retirada.html'>Voltar</a>";
} else {
    echo "<h2>Resumo da Retirada</h2>";
    echo "<p><strong>Título:</strong> $titulo</p>";
    echo "<p><strong>Aluno:</strong> $nome</p>";
    echo "<p><strong>E-mail:</strong> $email</p>";
}
?>