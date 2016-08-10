# CK2 Character Creator

To download the tool click [HERE](CharacterCreator.zip)

### Table of Contents
* [Introduction](#introduction)
* [Instructions](#instructions)
* [Tool Conventions](#tool-conventions)
* [Tips on Tool Usage](#tips-on-tool-usage)

### Introduction

This is a Windows Forms tool that is useful for quickly creating random characters for large total conversion map mods.
This tool works especially well if you want to create shattered world situations where each county is ruled by a different dynasty.

Using the tool you can specify a province directory to read from, assign an output directory where the character files for each
province will be generated to, and specify a culture names file from which random names can be generated.

Screenshot of the tool:
![alt tag](characterCreatorScreenshot.png)

****

### Instructions

1. To download this tool click [here](CharacterCreator.zip) or visit the Paradox Forum Thread [here]()
2. Unzip the file to any desired location
3. Open the file settings.txt
    * **Make sure the attributes you specify have a space to the right of the equals sign**
    * **start_date** specifies the year for which the mod you create starts to be playable.
      *  The characters generated will be all be alive at the starting date except the mother and father of the current head
         of the dynasty.
    * **culture** specifies the culture of the characters that will be generated
    * **religion** specifies the religion of the characters that will be generated
    * **character_id_from_province_multiplier** specifies what will be the starting(lowest) ID for characters in a province.
      * The starting ID is calculated as: `startingID_InProvince = provinceID * character_id_from_province_multiplier`
      * By convention the head of each dynasty in a province will have the lowest ID in that given province.
        * For example if `character_id_from_province_multiplier = 100` and we are looking at a province with ID = 8 then 
          the head of the dynasty in that province will have a characterID of 800.
    * **dynasty_id_from_province_multiplier** specifies what will be the dynastic ID of the characters generated in that province.
      * Works the same way as `character_id_from_province_multiplier` where the dynasticID in a province given as:
        `dynastyID_of_characters_in_a_province = provinceID * dynasty_id_from_province_multiplier`
      * All dynastic characters in a province will share the same dynasty which is what is expected.
    * **mean_age_of_character_head** specifies the mean age of the head of the dynasty and all the currently alive dynastic members.
      * In the current version of this tool it **must be an age above 16**
    * **age_variance_of_character_head** specifies how much from the `mean_age_of_character_head` can the age of the head of the dynasty
        and all the currently alive dynastic members vary.
      * For example if `mean_age_of_character_head = 25` and `age_variance_of_character_head = 5` the ages of the characters 
        that will be created will be between 20 and 30 inclusive.
      * In the current version of this tool **make sure `age_variance_of_character_head` does not cause the possibility of creating a 
        character younger than 16** so `mean_age_of_character_head - age_variance_of_character_head >= 16`
    * **mean_number_of_traits** is an attribute currently not used in the current version of the tool
      * **Do not delete** its line from `settings.txt` file
    * **number_of_traits_variance** is an attribute currently not used in the current version of the tool
      * **Do not delete** its line from `settings.txt` file
    * **mean_skill_values** specifies the mean value of the basic 5 skill attributes(diplomacy, martial, stewardship, intrigue, learning).
    * **skill_values_variance** specifies how much the skill values can vary from `mean_skill_values`
      * Make sure that the lowest possible skill value is not a negative value
    * **mean_life_expectancy** specifies what is the mean life expectancy of the currently living dynastic characters
    * **life_expectancy_variance** specifies how much from the `mean_life_expectancy` the life expectancy of characters can vary
      * Make sure that the lowest life expectancy is larger than the oldest possible living character given by
        `mean_age_of_character_head + age_variance_of_character_head`
4. Before running the executable under the **names** folder which is located in the same folder as the executable paste your name files
   in it. Name files are just text files with a list of names based on culture
    * In the screenshot above I used the `italian.txt` to make all my characters have italian based names
    * Here is what's included in the `italian.txt' file:
      ```
      male_names = {
		    Abbondanzio Abbondio Abelardo Abelino Achille Adalberto Albert Adelfo Adelmio Adelmo Adone Adriano Agapito Agostino Aimone Alamanno Alarico
		    Albano Alberico Alberto Albert Albino Alboino Alcide Aldobrandino Aleardo Aleramo Alessandro Alexander Alessio Alighiero Alvise Ambrogio Amedeo
		    Anastasio  Andrea Andrew Angelo Angel Annibale Anselmo Antonino Antoninus Antonio Antoninus Antoniotto Arcibaldo Arderico Armando Arnolfo
		    Arrigo Arsenio Artemio Ascanio Astorre Atenolfo Attilio Augusto Aurelio Aurelius Ausilio Ausonio Averado Azzo Azzone Baldassarre Baldovino Baldwin
		    Barnaba Bartolomeo Bartolomeus Basilio Basil Bassiano Basso Battista Beltrano Benedetto Benedict Benvenuto Berardo Bernab Bernard Bernardo Bernard Berto
		    Bertoldo Biagio Bonaventura Bonifacio Bonifacius Borso Bruno Bruto Buonconte Buoso Callisto Camillo Camillus Candido Cangrande Carlo Cassio Castore Cataldo
		    Catone Cecco Cesare Chiaffredo Chiano Ciro Ciuccio Claudio Clemente Clement	Comita Conone Cornelio Cornelius Corradino Corrado Konrad Cosimo Cosma Costante Costantino
		    Costanzo Cristoforo Christopher Damiano Damian Davide David Demetrio Demetrius Dioniso Dionysus Domnico Dominic Durante Eduardo Edward Elio Emmanuele Manuel
		    Ennio Enrico Henry Enzio Enzo Ercole Eriprando Ermenegildo Ettore Eugenio Eugene Ezio Ezzelino Fabrizio Fausto Federigo Frederick Felice Felix Ferdinando
		    Ferdinand Ferruccio Filippo Philip Fiorello Flavio Folco Folke Fortunato Fosco Francesco Francis Fresco Gabriele Gabrino Gaetano Galasso Galeazzo Galeotto Gaspare
		    Gastone Gaston Gelasio Gentile Geraldo Gerald Gerardo Gerard Germano Gerolamo Gherardo Giacinto Giacomo Gian Gianfranco Gianleone Giano Giberto Gilberto Gilbert
		    Giolio Giordano Giorgio George Giovanni Giulio Giuseppe Goffredo Godfrey Gregorio Gregory Gualtiero Guarnito Guerrino Guglielmo Guido Guy Guidone Guy
		    Guigliadore Iacopo Igino Innocenzo Ippolito Isnardo Jacopo Jacob Lamberto Lambert Landolfo Landone Lanfranco Lattanzio Lazzarino Lazzaro
		    Lealdo Leonardo Leone Leo Leonello Leopoldo Libero Lionello Livio Lodovico Lorenzo Luca Luchino Lucio Lucius Luigi Malacresta Manfredo Manuele Manuel
		    Marco Marcus Mariano Marius Marino Mario Marius Marsiglio Martino Martin Massimo Mastino Matteo Matthew Merigo Michelangelo Michele Michael  Napoleone Nazareno
		    Nestore Niccol Nicola Nino Nolfo Oberto Obizzino Obizzo Oddone Omero Onorio Oreste Orlando Ottavio Ottobono Ottone Otto Pagano Pancrazio Pandolfo Paolo Pasquale
		    Pascal Patrizio Patrick Pellegrino Pericle Pietro Peter Pio Prospero Rafaello Radul Raimondo Raymond Rainero Raineri Riccardo Richard Rinaldo Reinhold Rizzardo
		    Roberto Robert Rodolfo Rolando Rosso Ruggiero Salinguerra Salvatore Salvestro Sante Sancho Saverio Sciarra Sebastiano Sebastian Secondotto Serafino Sergio Sesto
		    Settimio Severino Severo Silvano Silvestro Simone Simon Simonetto Sinibaldo Sinucello Sozzo Spinetto Stefano Stephen Stentore Taddeo Tedaldo Tedice Teodoro Tibaldo
		    Theobald Tiziano Tommaso Torgodorio Torquato Ubaldo Uberto Ugo Hugh Ugoccione Ugolino Umberto Humbert Urbano Valentino Valentin Valerio Vincentello Vincenzo Vincent
		    Virginio Vitale Vittore Vittorio Zaccaria
	    }
		
        female_names = {
		    Abelina Adalberta Adalgisa Adelaida Adelaide Adelasia Adelia Adela Adriana Agalina Agnese Agnes Agostina Albina Alda Alessandra Alfonsina Alisia Alice Aloisia
		    Amalia Amelia Ambrosia Anastasia Anastasia Anna Anna Antonella Antonia Argentina Augusta Aurelia Ausilia Ausonia Beatrice Beatrice Benedetta Benedicta Benilde Berenice
		    Berta Bianca Blanche Bona Bonne Brunilde Brunhilda Camilla Candida Caracosa Carla Carola Caterina Catherine Cecilia Cecilia Clara Clara Claudia Clorinda 
		    Clotilde Clotilde Constanza Constance Cornelia Delinda Dora Edda Elena Helen Eleonora Eleanor Elisa Elisabeth Elisabetta Elisabeth Ermenegilda Eudossia Eugenia
		    Fausta Felicia Felicita Filippa Philippa Filomena Flavia Flora Flora Fortunata Fosca Francesca Francesca Froizza Giacinta Ginevra Giovanna Giuditta Giulia Juliana 
		    Giuseppa Ippolita Isabella Elisabeth Joscella Laura Laura Lavinia Leonide Letizia Lidia Livia Lodovica Lucia Lucia Lucinetta Lucrezia Maddalena Magdalena Marcella 
		    Margherita Margaret Maria Maria Mariana Marietta Martina Matilda Matilda Micaela Nunzia Paola Paula Patrizia Patricia Renata Ricciarda Ricarda Silvana
		    Sofia Sophia Stefania Stephania Tiziana Tomasina Valentina Violante Yolanda Virginia
	    }
      ```
    * Make sure you follow the same syntax convention when creating other name files for other cultures
5. After having done all the above steps run the executable and you will be prompted with same screen as the screenshot.
    * **Choose Province Folder** specifies the folder in which you have the provinces of your mod normally that is under
      `C:\Users\MyUserName\Documents\Paradox Interactive\Crusader Kings II\mod\MyModeName\history\provinces`
      * If you don't want to generate characters for all the provinces you should make another folder with the subset of the provinces
        for which you want to create characters and put that folder address in the `Choose Province Folder`
    * **Choose Output Folder** specifies the folder in which the created character files will be placed
      * Do not specify the characters folder of your mod directly. Instead specify a new folder and copy over any desired files that were
        generated.
    * **Culture Name File** specifies the name file that will be used to generate names for all the characters. Follow step 4 to
      for more details. These files must be placed in the names folder. Clicking the dropdown should display all the files placed
      in the names folder, or you can write the file name explicitly with the `.txt` extension.
6. Having all the steps above you can press the Generate Characters button and test out your new characters!

### Tool Conventions
* The current head of a dynasty in a given province will always have the lowest Character ID in that province.
* The father of the current head of the dynasty will have an ID of `HeadID + 1` and the mother of the current head of the dynasty will
  have an ID of `HeadID + 2`.
  * For example if the current head CharacterID of a dynasty is 200 then the head's father will have a CharacterID of 201 and the head's mother will
    have an ID of 202.
* The parents of the current head of the dynasty will be both dead before the starting date of the game.
* The current head of the dynasty will have:
  * 0-3 sisters that can be both younger and older than the current head
  * 0-3 brothers that are strictly younger than the current head
  * The brothers of the head have a 50% change of being married to a non-dynastic character (namely a commoner) which is also randomly generated and part
    and documented with a characterID of plus one of their husband.
    * For example if a brother has a CharacterID of 55 and he is married then his wife has a characterID of 56.
* The name files in the names folder must have at least 5 distinct female and male names.

### Tips on Tool Usage
This tool is designed with the mindset of quickly creating random characters especially for new map mods with shattered world situations. That being
said to get most out of it start generating random characters for provinces grouped by their culture.

Copy all provinces of a given culture to another folder and make sure you use that as reference. This will prevent generating characters
for all provinces and thus you can steadily build your way up culture by culture.

For each province there will be a unique dynasty. Of course the title holders will no be assigned unless you do it in the title files.
However you can use the County Title Creator tool that I made which will allow you to quickly assign the titles to the newly created characters.
You can view the forum thread [here](https://forum.paradoxplaza.com/forum/index.php?threads/ck2-simple-county-title-creator.961353/#post-21678093) and view its
documentation [here](https://github.com/aristotle333/CK2CountyTitleCreator).

Make sure you stick to the current tool conventions as specified above.

Make sure the names file have the same format as in the example above and there are at least 5 distinct male and female names.

****
[MIT License](LICENSE.md)
****
Created by [Aristotelis Sigiouan Leventidis](https://github.com/aristotle333)