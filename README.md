# 🐚 Simple Shell — `hsh`

## 👀 Aperçu

Le shell est un programme qui :
1. affiche un prompt (si interactif),
2. lit l’entrée utilisateur (stdin),
3. tokenize la ligne en commande + arguments,
4. gère les builtins,
5. recherche la commande via `PATH` si nécessaire,
6. exécute le programme dans un processus enfant,
7. renvoie un code de sortie.

---

## ✅ Fonctionnalités

- Exécution de commandes via chemins absolus/relatifs (`/bin/ls`)
- Résolution des commandes via la variable d’environnement `PATH`
- Gestion des arguments
- Gestion des erreurs (commande introuvable, permissions, etc.)
- Mode interactif + non-interactif (pipes)

Pawnee, Anthony D.
