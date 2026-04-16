const form = document.getElementById('formCadastro');
const btnEnviar = document.getElementById('btnEnviar');
const divErros = document.getElementById('divErros');
const camposInputs = form.querySelectorAll('input, select');

camposInputs.forEach(campo => {
    campo.addEventListener('input', () => {
        campo.classList.remove('campo-invalido');
    });
});

btnEnviar.addEventListener('click', (event) => {
    event.preventDefault();

    let erros = [];
    divErros.style.display = 'none';
    divErros.innerHTML = '';
    camposInputs.forEach(campo => campo.classList.remove('campo-invalido'));

    const nome = document.getElementById('nome').value.trim();
    const ra = document.getElementById('ra').value.trim();
    const email = document.getElementById('email').value.trim();
    const curso = document.getElementById('curso').value;
    const periodo = document.getElementById('periodo').value;
    const autorizacao = document.getElementById('autorizacao').checked;

    if (nome.length < 3) {
        erros.push("Nome deve ter no mínimo 3 caracteres.");
        document.getElementById('nome').classList.add('campo-invalido');
    }

    if (ra === "" || isNaN(ra)) {
        erros.push("RA deve conter apenas números.");
        document.getElementById('ra').classList.add('campo-invalido');
    }

    const posicaoAt = email.indexOf('@');
    const posicaoPontoDepoisDoAt = email.indexOf('.', posicaoAt);
    if (email === "" || posicaoAt === -1 || posicaoPontoDepoisDoAt === -1 || posicaoPontoDepoisDoAt <= posicaoAt + 1) {
        erros.push("O e-mail deve conter '@' e pelo menos um '.' após o '@'.");
        document.getElementById('email').classList.add('campo-invalido');
    }

    if (curso === "") {
        erros.push("Selecione um curso.");
        document.getElementById('curso').classList.add('campo-invalido');
    }

    if (periodo === "") {
        erros.push("Selecione o período.");
        document.getElementById('periodo').classList.add('campo-invalido');
    }

    if (!autorizacao) {
        erros.push("Autorize o uso de dados.");
    }

    if (erros.length > 0) {
        let lista = "<h3>Erros encontrados:</h3><ul>";
        erros.forEach(msg => {
            lista += "<li>" + msg + "</li>";
        });
        lista += "</ul>";

        divErros.innerHTML = lista;
        divErros.style.display = 'block';
        window.scrollTo(0, 0);
    } else {
        form.submit();
    }
});

form.addEventListener('reset', (e) => {
    e.preventDefault();

    divErros.style.display = 'none';

    camposInputs.forEach(campo => {
        campo.classList.remove('campo-invalido');
    });

    const temConteudo = Array.from(camposInputs).some(c => (c.type !== 'checkbox' && c.value !== "") || (c.type === 'checkbox' && c.checked));

    if (temConteudo) {
        divErros.style.display = 'block';
        divErros.innerHTML = `
                <h3>Limpar formulário?</h3>
                <button type="button" id="sim" style="background:#d9534f; color:white; padding:5px; margin-right:10px; border:none; border-radius:4px; cursor:pointer;">Pode crê, manda bala!</button>
                <button type="button" id="nao" style="background:#5bc0de; color:white; padding:5px; border:none; border-radius:4px; cursor:pointer;">Lá ele</button>
            `;

        document.getElementById('sim').addEventListener('click', () => {
            form.reset();
            camposInputs.forEach(c => c.value = '');
            divErros.style.display = 'none';
            divErros.innerHTML = '';
            camposInputs.forEach(c => c.classList.remove('campo-invalido'));
        });

        document.getElementById('nao').addEventListener('click', () => {
            divErros.style.display = 'none';
            divErros.innerHTML = '';
        });
    }
});