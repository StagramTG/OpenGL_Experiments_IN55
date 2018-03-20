# Mise en place du projet

- Cloner le dépôt depuis Github dans Visual Studio ou avec l'invite de commande Git.
- Ouvrir le dépôt avec visual studio.
- Vérifier que les configs de build (Debug et Release) sont en Win32.
- Lancer une première build en Debug qui va créer les dossier de génération et ne pas se lancer car il manque les dlls.
- Copier les dlls de Debug depuis le dossier vendors/dll/dll_Debug/ dans le dossier contenant l'exécutable généré.
- Relancer le projet depuis Visual Studio et il devrait maintenant se lancer.