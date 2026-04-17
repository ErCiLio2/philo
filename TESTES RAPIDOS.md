RESULTADOS DOS TESTES - PHILOSOPHERS

testes philoosophers


# 💀 1. SINGLE PHILOSOPHER (OBRIGATÓRIO) ✅
# 💀 2. MORTE PRECISA (timing crítico) ✅
# 💀 3. DEADLOCK TEST (clássico)  ✅ 
# 💀 4. HIGH CONTENTION (stress threads)

## 🔧 Teste:

```bash
./philo 200 800 200 200
```

## ✅ Esperado:

* execução estável
* sem crash
* sem freeze

## ❌ Erros:

* segfault
* race condition
* print corrompido

---

# 💀 5. FAST DEATH (timing apertado)

## 🔧 Teste:

```bash
./philo 5 100 60 60
```

## ✅ Esperado:

* morte rápida e consistente
* monitor reage imediatamente

## ❌ Erros:

* sobreviver tempo demais
* monitor atrasado
* false death

---

# 💀 6. ALL MUST EAT (condição final)

## 🔧 Teste:

```bash
./philo 5 800 200 200 3
```

## ✅ Esperado:

* cada filósofo come 3 vezes
* programa termina automaticamente

## ❌ Erros:

* não termina nunca
* deadlock no final
* contador errado (race)

---

# 💀 7. EDGE CASE ZERO SLEEP

## 🔧 Testes:

```bash
./philo 2 800 0 0
./philo 5 800 0 0
```

## ✅ Esperado:

* execução rápida
* sem crash
* sem freeze

## ❌ Erros:

* loop infinito
* starvation
* divisão por zero lógica

---

# 💀 8. EXTREME FAST DEATH

## 🔧 Teste:

```bash
./philo 4 50 20 20
```

## ✅ Esperado:

* morte quase instantânea
* sem prints depois da morte

## ❌ Erros:

* demora a morrer
* múltiplas mortes impressas
* race no stop

---

# 💀 9. PRINT SAFETY TEST

## 🔧 Teste:

qualquer simulação longa

## ✅ Esperado:

* logs limpos:

```
timestamp id action
```

## ❌ Erros:

* linhas misturadas
* prints após death
* output quebrado

---

# 💀 10. STABILITY TEST (loop longo)

## 🔧 Teste:

```bash
./philo 50 800 200 200
```

rodar várias vezes

## ✅ Esperado:

* sempre comportamento igual
* sem leaks
* sem crash random

## ❌ Erros:

* comportamento aleatório
* crash intermitente

---

# 💀 11. MEALS LIMIT TEST

## 🔧 Teste:

```bash
./philo 4 800 200 200 1
```

## ✅ Esperado:

* cada filósofo come 1 vez
* programa termina limpo

## ❌ Erros:

* não termina
* contador errado
* deadlock final

---

# 💀 12. MONITOR RACE TEST (muito importante)

## 🔧 Teste:

qualquer cenário rápido:

```bash
./philo 5 200 100 100
```

## ✅ Esperado:

* morte detectada instantaneamente
* sem delay visível

## ❌ Erros:

* +10ms / +50ms atraso
* prints depois da morte

---


