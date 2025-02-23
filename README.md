# **Conectando o Arduino ao Node-RED e Integrando com MQTT e WebSocket Clients**

## **📌 Introdução**

Este documento descreve um processo passo a passo para **ler sinais do Arduino, conectar ao Node-RED e enviar dados via MQTT para um broker**, utilizando **WebSocket Clients como Mosquitto e HiveMQ**. Este guia é voltado para alunos que estão aprendendo sobre **Internet das Coisas (IoT), automação e comunicação de dados**.

A estrutura do processo será:

1. **Arduino** lê um sensor (exemplo: um potenciômetro).
2. **Node-RED** recebe esses dados pela porta serial.
3. **Node-RED publica os dados em um broker MQTT (Mosquitto ou HiveMQ).**
4. **Clientes MQTT/WebSocket (como HiveMQ WebSocket Client) podem visualizar esses dados remotamente.**

---

## **📡 O que é MQTT?**

**MQTT (Message Queuing Telemetry Transport)** é um **protocolo leve de comunicação** ideal para IoT. Ele segue o modelo **publicador/assinante**, onde:

- **Dispositivos publicam mensagens** em tópicos específicos.
- **Outros dispositivos (assinantes) escutam esses tópicos** e recebem as mensagens automaticamente.

Isso permite **comunicação eficiente e em tempo real** entre sensores, servidores e aplicações web.

---

## **🔗 Como o Node-RED, MQTT, Brokers e WebSocket Clients se Relacionam?**

- **Node-RED** atua como **intermediário** entre o **Arduino** e a **rede MQTT**.
- **MQTT Broker** (Mosquitto ou HiveMQ) **recebe os dados do Node-RED** e os **redistribui para clientes conectados**.
- **WebSocket Clients** (como o HiveMQ WebSocket Client) podem **visualizar os dados MQTT em tempo real na web**.

🚀 Isso permite integrar sensores físicos a dashboards e aplicações de forma simples e eficiente.

---

# **📖 Passo a Passo**

### **1️⃣ Conectando o Node-RED ao Mosquitto MQTT Broker**

### **🛠 Configurar o MQTT Out no Node-RED**

1. **Abra o Node-RED** (`http://127.0.0.1:1880`).
2. **Arraste um nó `mqtt out` para a área de trabalho**.
3. **Clique duas vezes no nó `mqtt out` e configure:**
   - **Broker (Servidor MQTT):** `test.mosquitto.org`
   - **Porta:** `1883`
   - **QoS:** `0`
   - **Tópico:** `montecarlo/potenciometro`
   - **Retain:** Desmarcado
4. **Conecte um nó JSON ao `mqtt out` para garantir que os dados sejam enviados corretamente.**
5. **Clique em "Deploy".**

✅ **Agora, o Node-RED está publicando os dados no Mosquitto MQTT Broker!**

### **🖥 Visualizar os Dados com Eclipse Mosquitto WebSocket Client**

1. **Acesse** 👉 [Eclipse Mosquitto WebSocket Client](https://www.emqx.io/online-mqtt-client)
2. **Configure a conexão:**
   - **Broker:** `test.mosquitto.org`
   - **Porta:** `8081`
   - **Client ID:** `montecarlo-web`
   - **Clique em "Connect".**
3. **Após conectar, clique em "Add new Topic subscription"** e insira: montecarlo/potenciometro
4. **Clique em "Subscribe".**

✅ **Agora, os dados devem aparecer no painel do Mosquitto WebSocket Client!** 🎉

---

### **2️⃣ Conectando o Node-RED ao HiveMQ Cloud MQTT Broker**

### **🛠 Configurar o MQTT Out no Node-RED**

1. **Abra o Node-RED**.
2. **Arraste um nó `mqtt out` para a área de trabalho**.
3. **Clique duas vezes no nó `mqtt out` e configure:**
- **Broker:** `SEU_CLUSTER.s1.eu.hivemq.cloud`
- **Porta:** `8883`
- **Client ID:** `node-red-client`
- **Usuário e Senha:** *(Defina no HiveMQ Cloud)*
- **Tópico:** `montecarlo/potenciometro`
4. **Clique em "Deploy".**

✅ **Agora, o Node-RED está enviando os dados ao HiveMQ Cloud!**

### **🖥 Visualizar os Dados no HiveMQ WebSocket Client**

1. **Acesse** 👉 [HiveMQ WebSocket Client](http://www.hivemq.com/demos/websocket-client/)
2. **Configure a conexão:**
- **Host:** `SEU_CLUSTER.s1.eu.hivemq.cloud`
- **Porta:** `8884`
- **Client ID:** `montecarlo-web`
- **Usuário e Senha:** *(Os mesmos usados no Node-RED)*
- **Clique em "Connect".**
3. **Clique em "Add new Topic subscription"** e insira:
