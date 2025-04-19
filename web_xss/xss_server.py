from flask import Flask, request, redirect
import os

app = Flask(__name__)

MENSAJES_FILE = 'mensajes.txt'

@app.route('/', methods=['GET', 'POST'])
def home():
    if request.method == 'POST':
        mensaje = request.form.get('mensaje', '')
        # Guardar el mensaje tal cual, sin validar ni filtrar (vulnerabilidad)
        with open(MENSAJES_FILE, 'a', encoding='utf-8') as f:
            f.write(mensaje + '\n')
        return redirect('/')

    # Mostrar todos los mensajes
    mensajes = []
    if os.path.exists(MENSAJES_FILE):
        with open(MENSAJES_FILE, 'r', encoding='utf-8') as f:
            mensajes = f.readlines()

    pagina = '''
    <html>
    <head><title>Demo Stored XSS Vulnerable</title></head>
    <body>
        <h1>Formulario de comentarios</h1>
        <form method="POST">
            <input type="text" name="mensaje" placeholder="Escribe tu mensaje" size="50">
            <input type="submit" value="Enviar">
        </form>
        <h2>Mensajes anteriores:</h2>
    '''

    for m in mensajes:
        pagina += f'<p>{m.strip()}</p>\n'

    pagina += '''
    </body>
    </html>
    '''

    return pagina

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5001, debug=True)
