# Conectando-o-Arduino-ao-Node-RED-e-Integrando-com-MQTT-e-WebSocket-Clients

📌 Introdução

Este documento descreve um processo passo a passo para ler sinais do Arduino, conectar ao Node-RED e enviar dados via MQTT para um broker, utilizando WebSocket Clients como Mosquitto e HiveMQ. Este guia é voltado para alunos que estão aprendendo sobre Internet das Coisas (IoT), automação e comunicação de dados.

A estrutura do processo será:

Arduino lê um sensor (exemplo: um potenciômetro).

Node-RED recebe esses dados pela porta serial.

Node-RED publica os dados em um broker MQTT (Mosquitto ou HiveMQ).

Clientes MQTT/WebSocket (como HiveMQ WebSocket Client) podem visualizar esses dados remotamente.

📡 O que é MQTT?

MQTT (Message Queuing Telemetry Transport) é um protocolo leve de comunicação ideal para IoT. Ele segue o modelo publicador/assinante, onde:

Dispositivos publicam mensagens em tópicos específicos.

Outros dispositivos (assinantes) escutam esses tópicos e recebem as mensagens automaticamente.

Isso permite comunicação eficiente e em tempo real entre sensores, servidores e aplicações web.

🔗 Como o Node-RED, MQTT, Brokers e WebSocket Clients se Relacionam?

Node-RED atua como intermediário entre o Arduino e a rede MQTT.

MQTT Broker (Mosquitto ou HiveMQ) recebe os dados do Node-RED e os redistribui para clientes conectados.

WebSocket Clients (como o HiveMQ WebSocket Client) podem visualizar os dados MQTT em tempo real na web.

🚀 Isso permite integrar sensores físicos a dashboards e aplicações de forma simples e eficiente.

📖 Passo a Passo

1️⃣ Conectando o Node-RED ao Mosquitto MQTT Broker

🛠 Configurar o MQTT Out no Node-RED

Abra o Node-RED (http://127.0.0.1:1880).

Arraste um nó mqtt out para a área de trabalho.

Clique duas vezes no nó mqtt out e configure:

Broker (Servidor MQTT): test.mosquitto.org

Porta: 1883

QoS: 0

Tópico: montecarlo/potenciometro

Retain: Desmarcado

Conecte um nó JSON ao mqtt out para garantir que os dados sejam enviados corretamente.

Clique em "Deploy".

✅ Agora, o Node-RED está publicando os dados no Mosquitto MQTT Broker!

🖥 Visualizar os Dados com Eclipse Mosquitto WebSocket Client

Acesse 👉 Eclipse Mosquitto WebSocket Client

Configure a conexão:

Broker: test.mosquitto.org

Porta: 8081

Client ID: montecarlo-web

Clique em "Connect".

Após conectar, clique em "Add new Topic subscription" e insira:

montecarlo/potenciometro

Clique em "Subscribe".

✅ Agora, os dados devem aparecer no painel do Mosquitto WebSocket Client! 🎉

2️⃣ Conectando o Node-RED ao HiveMQ Cloud MQTT Broker

🛠 Configurar o MQTT Out no Node-RED

Abra o Node-RED.

Arraste um nó mqtt out para a área de trabalho.

Clique duas vezes no nó mqtt out e configure:

Broker: SEU_CLUSTER.s1.eu.hivemq.cloud

Porta: 8883

Client ID: node-red-client

Usuário e Senha: (Defina no HiveMQ Cloud)

Tópico: montecarlo/potenciometro

Clique em "Deploy".

✅ Agora, o Node-RED está enviando os dados ao HiveMQ Cloud!

🖥 Visualizar os Dados no HiveMQ WebSocket Client

Acesse 👉 HiveMQ WebSocket Client

Configure a conexão:

Host: SEU_CLUSTER.s1.eu.hivemq.cloud

Porta: 8884

Client ID: montecarlo-web

Usuário e Senha: (Os mesmos usados no Node-RED)

Clique em "Connect".

Clique em "Add new Topic subscription" e insira:

montecarlo/potenciometro

Clique em "Subscribe".

✅ Agora, os dados devem aparecer no painel do HiveMQ WebSocket Client! 🎉

3️⃣ Receber os Dados com MQTT In no Node-RED

Arraste um nó mqtt in para a área de trabalho.

Clique duas vezes no nó mqtt in e configure:

Broker: test.mosquitto.org (ou seu broker HiveMQ)

Porta: 1883 (ou 8883 se usar TLS no HiveMQ Cloud)

Tópico: montecarlo/potenciometro

Arraste um nó json para converter a string JSON recebida em objeto JSON.

Conecte o nó json ao debug e ui_gauge para exibir no Dashboard.

Clique em "Deploy".

✅ Agora, os dados do MQTT estão chegando no Node-RED e podem ser visualizados no Dashboard! 🎯

📌 Conclusão

Agora você tem um sistema Arduino → Node-RED → MQTT → WebSocket Client totalmente funcional! 🚀

Mosquitto é um broker MQTT open-source gratuito.

HiveMQ Cloud é um broker MQTT seguro e escalável.

Node-RED permite integrar sensores físicos a serviços na web.

WebSocket Clients (Mosquitto e HiveMQ) permitem visualizar os dados MQTT em tempo real.

Se precisar de mais ajustes ou otimizações, explore os recursos de Node-RED, MQTT e dashboards interativos! 🔥
