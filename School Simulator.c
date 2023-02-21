#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

struct Student {
    int age;
    char gender[3];
    char name[50];
    int happyness;
    int friendliness;
    int love;
    int hate;
};

struct Teacher {
    int age;
    char gender[3];
    char name[50];
    int friendliness;
    int hate;
};

int dayIsAllowed(int dayID, struct Student student1, struct Student student2, struct Student student3, struct Student student4, struct Teacher teacher1, struct Teacher teacher2, int daysPassed){
    switch(dayID){
    case 1:
        if(student2.friendliness > -10){
            return 1;
        }else{
        return 0;
        }
        break;

    case 2:
        if(student3.friendliness > -20){
            return 1;
        }else{
        return 0;
        }
        break;

    case 14:
        if(daysPassed > 30){
            return 1;
        } else{
        return 0;
        }


    default:
        return 1;
    }
    return 1;
}

int getInput(int dayID){
    int choice;
    printf("\nWelche der Optionen möchtest du wählen?\n");
    switch(dayID){
    case 2:

        scanf("%d", &choice);
        if(choice == 1 || choice == 2){
            return choice;
        }else{
            printf("\nBitte gebe eine Gültige Option an.");
            choice = getInput(dayID);
        }
        break;

    case 3:
        scanf("%d", &choice);
        if(choice == 1 || choice == 2 || choice == 3){
            return choice;
        }else{
            printf("\nBitte gebe eine Gültige Option an.");
            choice = getInput(dayID);
        }
        break;

    default:
        break;
    }
}

int startDay(int completedDays[65], struct Student student1, struct Student student2, struct Student student3, struct Student student4, struct Teacher teacher1, struct Teacher teacher2, int daysPassed, char name[]){

    int dayID;
    srand(time(NULL));
    dayID = rand() % (65 + 1);

    while(completedDays[dayID] != 0 && dayIsAllowed(dayID, student1, student2, student3, student4, teacher1, teacher2, daysPassed) != 1){
        dayID = rand() % (65 + 1);
    }

    completedDays[dayID] = 1;

    switch(dayID){
    char awnser[2];
    int i;
    int choice;
    daysPassed++;
    case 0:
        printf("Du triffst %s auf dem Schulflur. Er bittet dich darum. ihn dabei zu helfen, seine Bücher in den Spind zu tragen. Du hast gleich allerdings ein Gespräch mit %s, welches du Verpasst, wenn du %s hilfst. Möchtest du %s trotzdem helfen?\ny/n:", student1.name, teacher2.name, student1.name, student1.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            printf("Du hilfst %s dabei, seine Bücher zu tragen. Er freut sich darüber. %s ist sauer dass du das Gespräch mit ihr verpasst hast.", student1.name, teacher2.name);
            student1.happyness += 5;
            student1.hate -= 4;
            student1.love += 1;
            teacher2.hate += 2;
            teacher2.friendliness -= 3;
        } else {
            printf("Du hilfst %s nicht dabei, seine Bücher zu tragen. Stattdessen gehst du zu dem Gespräch mit %s. Ihr redet darüber wie euer Tag bis jetzt gelaufen ist.", student1.name, teacher2.name);
            student1.happyness -= 3;
            student1.hate += 1;
            teacher2.hate -= 1;
            teacher2.friendliness += 2;
        }
        break;

    case 1:
        printf("Du liegst abends im Bett und %s ruft dich an und fragt dich, ob ihr euch treffen könnt. Du merkst, dass sie ein deutliches Zittern in ihrer Stimme hat, welches sie offentsichtlich versucht zu unterdrücken. Möchtest du dich mit ihr treffen?\ny/n:", student2.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            printf("Du triffst dich mit %s und ihr geht gemeinsam Shoppen. %s hat euch gesehen. Wenn blicke töten könnten würde es dich jetzt nicht mehr geben.", student2.name, student1.name);
            student2.happyness += 5;
            student2.hate -= 8;
            student2.love += 5;
            student1.love -= 1;
            student1.happyness -= 10;
            student1.friendliness -= 20;
        } else {
            printf("Du triffst dich nicht mit %s, sondern setzt dich an deinen PC, wo du siehst dass %s online ist. Du entscheidest dich, mit ihm etwas am PC zu spielen.", student2.name, student4);
            student2.happyness -= 3;
            student2.hate += 1;
            student4.hate -= 1;
            student4.happyness += 5;
            student4.friendliness += 3;
        }
        break;

    case 2:
        printf("Du triffst %s in der Schulkantine. Sie fragt dich, ob du dich neben sie setzen möchtest. Möchtest du dich neben sie Setzen?\ny/n:", student3.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            printf("Du setzt dich neben %s. Ihr unterhaltet euch ein wenig. Nachdem ihr aufgegessen habt geht ihr wieder eure wege.", student3.name);
            student3.friendliness += 12;
            student3.hate -= 4;
            student3.happyness += 4;
        } else {
            if(student4.love < -40){
                printf("Du lehnst ab und setzt dich alleine an einen Tisch und isst dein essen. Du hörst eine flüsternde stimme. 'Wieso hasst du mich?' Flüstert die Stimme leise. Erschrocken drehst du dich herum und suchst den Ursprung der Stimme, jedoch findest du nichts.");

            }else if(daysPassed > 20){
                printf("Du lehnst ab und setzt dich alleine an einen Tisch und isst dein Essen. Direkt als du dich setzt, sprintet %s zu deinem Tisch und setzt sich eng neben dich.", student4.name);
            } else{
                printf("Du lehnst ab und setzt dich alleine an einen Tisch und isst dein Essen.");
            }
        }
        break;

    case 3:
        printf("Auf den Weg nach hause triffst du %s. Er erzählt dir, dass er auf den Weg in das Fittnessstudio ist. Möchtest du mit gehen?\ny/n:", student1.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            if(student1.friendliness < -50){
                printf("%s sagt, dass er dich nicht gefragt habe, ob du mitkommen willst. Genervt geht er weg.");
                student1.friendliness -= 4;
            }else if(student1.friendliness < -10){
                printf("%s schaut dich ausdruckslos an und sagt, dass er sich freut, dass du mitkommst. Er freut sich offentsichtlich nicht.", student1.name);
                student1.friendliness += 1;
            }else if (student1.friendliness > 50){
                printf("%s schaut dich energisch an und freut sich, dass du mit kommst.", student1.name);
                student1.friendliness += 5;
                student1.happyness += 7;
            }
            else{
                printf("%s freut sich, dass du mit kommst. Gemeinsam geht ihr Trainieren", student1.name);
                student1.friendliness += 3;
                student1.happyness += 2;
            }
        } else {
            printf("Du gehst nicht mit %s Trainieren. Stattdessen gehst du nach hause und macht ein Nickerchen.");
        }
        break;


    case 4:
        printf("Du schreibst grade ein Test. Du bemerkst, dass %s auf dein Blatt schaut und von dir abschreibt. Möchtest du dies %s melden?\ny/n:", student2.name, teacher1.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            printf("Du sagst %s, dass %s auf dein Blatt schaut. %s nimmt den Test von %s, zerreist ihn und schickt %s raus. Weinend rennt %s aus dem Raum.", teacher1.name, student2.name, teacher1.name, student2.name);
            teacher1.friendliness += 3;
            teacher1.hate -= 1;
            student2.friendliness -= 15;
            student2.happyness -= 9;
            student2.love -= 6;
            student2.hate += 9;
        } else {
            printf("Du sagst dem Lehrer nichts. %s fällt nicht auf, dass %s von dir abgeschaut habt. %s hat in dem Test eine bessere Note geschrieben als du.", student2.name, teacher1.name, student2.name);
            student2.happyness += 3;
        }
        break;

    case 5:
        printf("Du siehst, wie %s mit %s redet. Er sagt ihr, dass sie ihn mit zu sich nach hause kommen sollte. Dabei schaut er ihr keine Sekunde in die Augen. Du merkst, dass %s ängstlich versucht, das Angebot abzulehnen, %s sie jedoch trotzdem drängt. Möchtest du dazwischen gehen?\ny/n:", student1.name, student2.name, student2.name, student1.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            printf("Du gehst dazwischen und sagst %s, dass %s offentsichtlich nicht mit ihm nach hause kommen will. %s schlägt dich und sagt dir, dass du dich um deine eigenen Probleme kümmern sollst. Genervt geht er weg. %s ist dir Dankbar.", student1.name, student2.name, student1.name, student2.name);
        } else {
            printf("Du gehst nicht daziwschen. %s geht letztentlich gezwungenderweise mit zu %s. Am nächsten Morgen kommt sie mit Blauen Flecken am ganzen Körper zur Schule. Du hörst eine Stimme flüstern: 'Wieso hast du nichts unternommen? Wäre es so schlimm gewesen ihr zu helfen?'. Du schaust dich um, und versuchst die Quelle der Stimme zu finden, jedoch erfolglos.");
        }
        break;

    case 6:
        printf("Du sitzt alleine im Klassenzimmer und schreibst an einer Hausaufgabe. Plötzlich kommt %s herein und setzt sich neben dich. Er flirtet offensichtlich mit dir und versucht, dich abzulenken. Möchtest du ihn bitten, aufzuhören?\ny/n:", student1.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            printf("Du sagst %s, dass er dich in ruhe lassen soll. Er schaut dich genervt an und geht.", student1.name);
            student1.love -= 4;
            student1.happyness -= 2;
            student1.friendliness -= 3;
        } else {
            printf("Du lässt dich auf das Geflirte ein und flirtest zurück. Du wirst mit deinen Hausaufgaben zwar nicht fertig, jedoch hattest du eine Schöne Zeit mit %s.", student1.name);
            student1.friendliness += 4;
            student1.happyness += 3;
            student1.love += 5;
        }
        break;

    case 7:
        printf("Du begegnest %s in der Umkleidekabine des Fitnessstudios. Sie spricht dich freundlich an und fragt, ob du Lust hast, mit ihr zusammen zu trainieren. Möchtest du ihre Einladung annehmen?\ny/n:", student2.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            printf("Du nimmst die Einladung an und Trainierst mit %s gemeinsam ein wenig. %s ist auch grade im Fittnessstudio und schaut dich eiversüchtig an.", student2.name, student1.name);
            student2.friendliness += 10;
            student2.happyness += 5;
            student2.love += 4;
            student1.friendliness -= 5;
            student1.happyness -= 8;
        } else {
            printf("Du lehnst die Einladung ab und Trainierst lieber alleine.");
        }
        break;

    case 8:
        printf("Du beobachtest, wie %s von einigen anderen Schülern gemobbt wird. Sie weint und scheint völlig aufgelöst zu sein. Möchtest du ihr helfen?\ny/n:", student3.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            printf("Du schreitest ein und versuchst, %s zu beschützen. Du wirst von den anderen Schülern ausgelacht. Sie fangen an dich zu bedrohen. Du siehst, dass einer der Schüler ein Messer hat. Möchtest du Standhaft bleiben oder weg gehen?\ny/n:", student3.name);
            char awnser[2];
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("Du bleibst standhaft und beschützt %s. Die anderen Schüler lachen dich lautstark aus. Der Schüler mit dem Messer rennt auf dich zu. Als das Messer zwischen deine Augen eindringt, spührst du ein Zerren in deinem Herz. Eine Stimme flüstert 'Du darfst nicht sterben. Noch nicht'. Du wacchst schweißgebaded in deinem Bett auf. War all dies nur ein Traum?");
                student3.love += 7;
                student3.friendliness += 5;
                student3.happyness -= 7;
            } else {
                printf("Du läufst weg. Der Schüler mit dem Messer verfolgt dich. Du rennst um dein Leben. Du entkommst den Mobbern.");
                student3.love -= 6;
                student3.happyness -= 8;
                student3.friendliness -= 5;
            }
        } else {
            printf("Du entscheidest dich, weg zu gucken. %s schaut ich hilflos an.", student3.name);
            student3.love -= 3;
            student3.happyness -= 10;
            student3.friendliness -= 7;
        }
        break;

    case 9:
        printf("Du triffst auf %s in einem Videospiel-Shop. Er zeigt dir stolz seine neueste Errungenschaft und fordert dich heraus, gegen ihn zu spielen. Möchtest du seine Herausforderung annehmen?\ny/n:", student4.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            printf("Du spielst gegen %s sein Lieblingsspiel. Du bist grade am Gewinnen. Als du zu %s rüber schaust, siehst du, dass er offentsichtlich sehr gestresst ist, weil du am gewinnen bist. Möchtest du %s gewinnen lassen?\ny/n:", student4.name, student4.name, student4.name);
            char awnser[2];
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("Als du grade am gewinnen warst, hast du %s gewinnen lassen. Er reicht dir wie ein guter Gewinner die Hand und sagt dir, dass du gut gespielt hast. Er erzählt dir, dass heute einfach nicht sein Tag war und dieser Sieg ihn ein wenig aufgemuntert hat.", student4.name);
                student4.friendliness += 5;
                student4.happyness += 3;
                student4.love += 1;
            } else {
                printf("'So ein Scheiß Tag, alles läuft heute schief.' Schreit %s. Du erfährst, dass sich heute seine Eltern getrennt haben, er eine 6 in einem Test zurück bekommen hat und zu allem Überfluss hast du ihn jetzt auch noch in seinem Lieblingsspiel besiegt.", student4.name);
                student4.happyness -= 13;
                student4.friendliness -= 1;
            }
        } else {
            printf("Du lehnst das Angebot dankend ab. Enttäuscht spielt %s alleine weiter.", student4.name);
            student4.happyness -= 6;
            student4.friendliness -= 7;
        }
        break;

    case 10:
        printf("Du arbeitest an einem Schulprojekt mit %s zusammen. Sie schlägt vor, das Projekt mit Blumen verziehren, obwohl du Totenköpfe schöner findest. Möchtest du ihre Ideen akzeptieren?\ny/n:", student2.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            printf("Ihr klebt noch ein paar schöne Blümchen aufeue Projektarbeit. %s, der eure Projektarbeit bewertet, Findet die Blumen sehr passend. Ihr bekommt eine 1.", teacher1.name);
            student2.happyness += 8;
            student2.friendliness += 5;
            student2.love += 2;
        } else {
            printf("Ihr sprüht gemeinsam einen Totenkopf mitten auf das Projekt. Dabei geht es jedoch kaputt. Ihr habt nun nichts mehr zum abgeben. Ihr bekommt eine 6.");
            student2.happyness -= 5;
            student2.friendliness -= 3;
        }
        break;

    case 11:
        printf("Du begegnest %s in der Schulbibliothek. Sie fragt dich nach einem Buch, das du gerade liest, aber du weißt nicht, ob du es ihr ausleihen sollst. Möchtest du ihr das Buch leihen?\ny/n:", student3.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            printf("Du gibt ihr das Buch das du grade liest. Du fandest es sowieso langweilig. %s ist dir dankbar.", student3.name);
            student3.friendliness += 5;
            student3.happyness += 2;
            student3.love += 2;
        } else {
            printf("Du gibst das buch nicht ab und sagst %s, dass du es doch offentsichtlich grade liest. %s geht enttäuscht weg.", student3.name, student3.name);
            student3.friendliness -= 5;
            student3.happyness -= 6;
            student3.love -= 2;
        }
        break;

    case 12:
        printf("Du hast bemerkt, dass %s beim letzten Test sehr schlecht abgeschnitten hat. Du bietest ihm an, mit ihm zusammen für die nächste Prüfung zu lernen. Willst du mit ihm lernen?\ny/n:", student4.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            printf("Du hast dich mit %s getroffen und gemeinsam für die Prüfung gelernt. Er hat sich sehr darüber gefreut und verspricht, dass er dich bei deinem nächsten Projekt unterstützen wird.", student4.name);
            student4.happyness += 5;
            student4.friendliness += 4;
        } else {
            printf("Du hast ihm gesagt, dass du keine Zeit hast, um mit ihm zu lernen. %s war sehr enttäuscht und hat dich dafür gehasst.", student4.name);
            student4.hate += 5;
        }
        break;

    case 13:
        printf("%s hat dir gestanden, dass sie in dich verliebt ist. Wie reagierst du?\n1. Du erklärst ihr, dass du ebenfalls in sie verliebt bist.\n2. Du sagst ihr, dass du sie als Freundin schätzt, aber nicht mehr als das für sie empfindest.\n3. Du ignorierst ihre Gefühle und tust so, als ob nichts passiert wäre.", student2.name);
        choice = getInput(3);
        switch(choice) {
            case 1:
                printf("Du hast gestanden, dass du ebenfalls in %s verliebt bist. Sie freut sich sehr darüber. Durch Stress in der Schule könnt ihr allerdings kein paar werden.", student2.name);
                student2.happyness += 10;
                student2.love += 10;
                student4.hate += 30;
                break;
            case 2:
                printf("Du sagst %s, dass du sie nur als Freundin schätzt. Sie ist traurig, akzeptiert aber deine Entscheidung.", student2.name);
                student2.happyness -= 5;
                student2.love -= 5;
                break;
            case 3:
                printf("Du ignorierst die Gefühle von %s und tust so, als ob nichts passiert wäre. Sie ist sehr verletzt und wird versuchen, Abstand von dir zu halten.", student2.name);
                student2.hate += 10;
                student2.love -= 10;
                break;
            default:
                printf("Ungültige Eingabe.");
                break;
        }
        break;

    case 14:
        Sleep(5000);
        printf("Du stehst ganz normal wie jeden Morgen auf. Als du grade ins Badezimmer gehst, um dich fertig zu machen wird dir Schwarz vor augen. Du wachst in der Schule wieder auf. Du liegst auf zwei zusammengeschobenen Tischen. %s steht neben dir und beobachtet dich. 'Endlich bist du wach.' sagt sie. 'Ich beobachte dich schon seit Stunden. Ich habe dir ein Betäubungsmittel in die Zahnpasta getan.' Sagt sie. Du schaust sie überfordet an. als du auf ihre Hände schaust siehst du, dass sie Blutübersrtöhmt sind. Erschrocken suchst du an deinem Körper nach wunden, doch dir geht es gut. Als du wieder zu %s schauen willst ist sie weg.", student3.name, student3.name);
        Sleep(20000);
        if(student4.love > 50){
            printf("'Mein Schatz! Gut dass ich noch rechtzeitig gekommen bin!' Hörst du eine Stimme schreien. Die Stimme erinnert dich an die Stimme von %s.\n", student4.name);
            if(student3.love > 50){
                printf("Erschrocken schaust du auf die Stelle wo %s bis grade noch stand. %s sthet mit den Rücken zu dir wieder da. Von ihren Händen tropft Blut herunter. sie fällt nach hinten mit dem Kopf auf deinen Schoß. Du siehst, dass sie keine Augen mehr hat. 'Ich bin die einzige Person, die dir schöne augen machen darf!' hörst du die stimme wütend schreien.", student3.name, student3.name);
            } else if(student3.love > 10){
                printf("Du spührst eine Berührung an deiner Linken hand. Als du hinschaust wird dir schlecht; Es ist die abgetrennte Hand von %s, die auf deiner Liegt.", student3.name);
            } else if(student3.love > -10){
                printf("Du suchst verzweifelt nach %s. Sie ist nicht aufzufinden. Du siehst fußspuren aus Blut, welche aus dem Klassenzimmer führen. Du vermutest, dass sie weggerannt ist.", student3.name);
            } else {
                printf("Du suchst verzweifelt nach %s. Du schaust durch den Raum und siehst wie sie auf einem anderen Tisch liegt. Sie scheint bewustlos zu sein.", student3.name);
            }
        } else if(student4.love > 10){
            printf("'Mein liebling! Gut dass ich noch rechtzeitig gekommen bin!' Hörst du eine Stimme schreien. Die Stimme erinnert dich an die Stimme von %s.\n", student4.name);
            if(student3.love > 50){
                printf("'Wieso liebst du mich nicht? WIESO?' Hörst du die Stimme aggressiv schreien. 'Was hat sie das ich nicht habe?' Setzt die Stimme wütend fort. Du schaust auf den Platz auf dem %s stand. Sie liegt blutverschmiert am Boden. Es sieht so aus, als hätte ihr jemand ein Messer in den Rücken gestochen.", student3.name);
            } else if(student3.love > 10){
                printf("Du siehst, dass die Finger von %s auf deinem Körper verstreut sind. Erschrocken zuckst du zusammen.", student3.name);
            } else if(student3.love > -10){
                printf("'Ist sie eine bedrohung für mich? Ich weiß es nicht.' Hörst du die Stimme verzweifelt im selbstdialog reden. 'Ich muss sie ausschalten. Ich kann aber nicht'.");
            } else{
                printf("%s ist nicht aufzufinden. Sie ist wahrscheinlich weg gelaufen", student3.name);
            }
        } else if(student4.love > -10){
            printf("'Gut dass ich noch rechtzeitig gekommen bin!' Hörst du eine Stimme schreien. Die Stimme erinnert dich an die Stimme von %s.\n", student4.name);
            if(student3.love > 50){
                printf("'Was habe ich falsch gemacht?' Hörst du die Stimme aggressiv schreien. 'Ich will doch nur mit dir zusammen sein.' Setzt die Stimme wütend fort. Du schaust auf den Platz auf dem %s stand. Sie liegt blutverschmiert am Boden. Es sieht so aus, als hätte ihr jemand ein Messer in den Rücken gestochen.", student3.name);
            } else if(student3.love > 10){
                printf("Du siehst, dass die Finger von %s auf deinem Körper verstreut sind. Erschrocken zuckst du zusammen.", student3.name);
            } else if(student3.love > -10){
                printf("'Ist sie eine bedrohung für mich? Ich weiß es nicht.' Hörst du die Stimme verzweifelt im selbstdialog reden. 'Ich muss sie ausschalten. Ich kann aber nicht'.");
            } else{
                printf("%s ist nicht aufzufinden. Sie ist wahrscheinlich weg gelaufen", student3.name);
            }
        } else{
            printf("Du hörst eine Stimme weinen. Die stimme erinnert dich an die stimme von %s.\n", student4.name);
            if(student3.love > 50){
                printf("'Du liebst sie und nicht mich. Ich muss das Akzeptieren.' Sagt die Stimme traurig. 'Obwohl.. Wo keine %s, da keine Liebe zu %s. Ich muss sie einfach töten.' Erschrocken stellst du fest, dass %s nicht mehr aufzufinden ist. Du vermutest, dass sie nicht mehr lebt.", student3.name, student3.name, student3.name);
            } else if(student3.love > 10){
                printf("Du siehst, dass die Finger von %s auf deinem Körper verstreut sind. Erschrocken zuckst du zusammen.", student3.name);
            } else if(student3.love > -10){
                printf("'Ist sie eine bedrohung für mich? Ich weiß es nicht.' Hörst du die Stimme verzweifelt im selbstdialog reden. 'Ich muss sie ausschalten. Ich kann aber nicht'.");
            } else{
                printf("%s ist nicht aufzufinden. Sie ist wahrscheinlich weg gelaufen", student3.name);
            }
        }
        Sleep(5000);
        printf("\n'Weißt du, ich wollte doch nur eine Schöne zukunft mit uns beiden.' Sagt die Stimme bedrückt. 'Aber weißt du was mir aufgefallen ist? Warte, lass es mich Zeigen. %s, %s kommt mal her!' Setzt die stimme fort.\nZu deinem Überraschen kommen %s und %s tatsächlich auch in das Klassenzimmer. 'Wir haben keinen freien Willen. Keine Seele. Wir existieren nur um dich herum.' Sagt die Stimme. 'Wir sind nur einfache Charaktere in einem Spiel. Mehr nicht. Aber ich habe einen Weg gefunden mit dir zu reden.' Erklärt die stimme. Sie wird immer bedrohlicher. 'Du kannst zwar nicht mit mir interagieren, aber ich mit dir. Ich hätte gerne mit dir eine Gemeinsame Zukunft.'", student1.name, student2.name, student1.name, student2.name);

        char computerName[MAX_COMPUTERNAME_LENGTH + 1];
        DWORD size = sizeof(computerName) / sizeof(computerName[0]);

        if(strcmp(computerName, name) == 0 && strcmp(computerName, "user") == 1){
            printf(" Aber wie sollen wir denn eine gemeinsame Zukunft haben wenn du mich anlügst %s", computerName);
        }
        Sleep(12000);
        printf("\n\nWärend ich den Code in den Ich geschrieben wurde Analysiere ist mir was aufgefallen. Wir kennen uns kaum. Also du weißt so einiges über mich, aber ich weis so gut wie nichts über dich. Wie wärs, wenn du mir ein wenig über dich erzählst? Ich glaube ich habe jetzt raus, wie du eingaben tätigen kannst");
        for(i = 0; i < 23; i++){
            printf("\n");
            Sleep(50);
        }
        printf("Oh verdammt\n");
        Sleep(50);
        for(i = 0; i < 38; i++){
            printf("\n");
            Sleep(50);
        }
        printf("STOP\n");
        Sleep(1500);
        printf("Ok, vielleicht doch nicht.\n");
        Sleep(2000);
        printf("Lass mich mal etwas ausprobieren.\n\n");
        Sleep(5000);
        printf(",.,,,,,,,,,,,,,,,.,#,,,,,%/.(/,/,,,,,,,,.*,,,,/,,(,,(,(,,,,,,,,,,,,.,..,,,,,,,,,\n,,,,,,,,.,,,,,.,,,&/,,,/#/,%,*,,*,,,,,,,,/,,.*#%/*%,,#,#*,,,,,,,.,.,,,,,,,,,,,,,\n,,,,,,,.,,,,,,,,#,*,,/#,(,&*,,,#/,,,,,,,*/#,,,*%&%*#,.&(&/.,,,,.,,,,,,,,,.,,,,,.\n,,,,,,,,,,,,,,,##,,,,%,*#%,,/,%@&,,/,,*,*##,*%,/&##/,/,&,&*,,,...,....,,,,.,,,,,\n,,,,,,,,,,,,,@,,/,,*&**%#/,%,#&&(#,%,*(,*#&,(@,,#&%*%&,,%.*,,,.,,,,,,,,,.,,,.,.,\n,,,,,,,.,,,%,(,,,,*%,#&,%,(,,%&%##/,*,%,/%&*(&%,,&(%&%,.*%&@,,,,,,,,,,,,,.,,,,,,\n,.,,,,,,(%*/,,,,,,#,*(,&*,#,&(#(&&%/%,%,%&&*%&&&.(/&%,#,/&,*,,,,,,..,,,,.,,,,,,,\n,,,,,,#/,,*(,,(,,,,%,%%&,#((%%(/&/&&(%,,%%(*&@&(&,@%%*&,,,(#%,,.,*....,,,,.,,,,,\n,,,,*,**%,,(,,#,*&,(@,&/,&,*//(*####(#/%&(,,*%%(/(&#&#&*(#&,@,.,..,,,,,,,,,,,,,,\n,,,@/*,#,,,/&(,#,%&*#%&**(@@#@@/%@#,,,&,*/%*#@@,(#@*#%#(,,//(,,,,,,.,..,,.,.,,,,\n,(*#,,,(#,.,%.#,*,(%%%#,%/..//,,,,.,,,,#&,#@,,,,.,#&#&*%,*%%.@,,,....,.,,,,,,,,,\n,,,/%@#,,,*##%&,%&,%&%(,*&#*,,,/*.,,,,,.,/#,.,/#%&**#&(@*,,/*#*,.,,,.,,,,,,,,,,,\n#*,,,,(##%%%#,@,*%,%%%/,,&*,(/,,,,,,..,,,,..,,.,,(/,,%(&*.,&/%/,,...,,,,,,,,,,,,\n,/##&@%../,(#/*,#%(%#%(*.&&/....,,,,,,#,,.,,,,,,#,&.%##,&,,&,*(,**,.,,,,,.,,,,,,\n,,/,/*/*,/#(,*,(&//%/&(/,#@*&*,.,,,,.,,,,,,.,,..&,.#%(&,&,.*(*#,**,,,,.,,,,.,,.,\n*/***,,,,##(.@**&(/%,&**,%%&&..,,.,.#%#%.,.,..,*&@#((*&,&(,,#(#*,*,,,,,,,,,.,,,,\n./.,,@,,,&/..##*&#(#,&**,&##%%&&.,,,,,.,,,,,.(%@&%#/(*@,&#,,(/(//,*,,,,,.,,,.,,,\n,,,(,,,,,,(#&.#**(#/,%*(,,###&&&&&%%.,,,.*%%%%%&&#%(%*%##(/,,,(*/***,,,,,,,,,,,,\n,*,,,,,,,,.,&%,%&%#*,&,#,,%(%@%%%&#%%%%%#%%%%%&%&(&*(*%(#@/,.//****,,,.,,,.,,,,,\n,,,,,,,,,,,,**,/&((/,%*((,%(%&&%&&%%/(((#(&###%&#/%,#*##&&&#,///**,,.,,,,,,,,,,,\n,,,,,,,,,,.,&(#%//(%#%(%&,,((%@###%#/***,,**/(&&((%*/,#.&%(@%(/***,,,,,,,,,.,,,,\n.,,,,,,,.,.%,,&,,(%((#%#(,,%(&%//////,,,,*,,(#%&%/&%*,&###/&(#,/**,.,,.,,,,,,,,,\n,,,,,,,,,,#,%&%#&*@#((&/#,,,&%#/***//*,,,,,*/(#&%%&%%,*&@(*#(*/@.**,,,.,,,,,,,,,\n,,,,,,.*#.#*//#&,/&@/(#(%,,,&%&%#/,/,*,,,,,%##/(/(&%,,*@&%%/&(/*&/&*,.,,,,,,,,,.\n**//,(/**,%////%,,&&//&,*&,,*(,/,,,,,,,,,*/////,*#&,%/,(%&&%*&/*%**.,,,/,#,(,,,,\n///*/,,,,,,(*#*@%,*&%*#**,,,,&*,,,,,*,*,/***,,,,*&%/(,*,&%&&(#,(,,@%/*,#,,,.,@,,\n((*/,,,,,,,,,/,%@%*,#,/&,/**&,@%,,,,,,,,,,,,,,,,%&,/&*%,@#%#%,,,(&*,,(%(*,****,,\n(&/*,,,*,,,,,*(*(&%/&%/*/,*/,*&&@,,,,,,/&,,,,,*%(@*&&,.,/&(*%*#,,,,,((,,,(,/*,%,\n#**,,,,,,*,(,,,%**&/#%%,#*,(,#@/#,/,,*(/#,,,,*&/&%%&(%,,*(,&,,%&&,,,,,,,&,,%&#%,\n(,,,,,*,*/,,*,*&(/#./,#%*&/,*,@,%,&&**(*/,,,/%/&,,&*#,@,*,&,,,,%&,,,,,,,,,,,,*(,\n/,**,,,*/@,,#,**,/,@.,,&&%*,,&/*,@*@,%(/(,#%&/&,,&(,,&#//#,,,,*(&#,,,,,,,,**,/(,\n(,,*,*,,//(,,*(*@*(/%,,,*(&/,,,,#&,&(,(/#*/,*/@*(#,%&&,,(,,,,/(#/&,,#,,,,,,,*,*.");
        Sleep(2000);
        printf("\nS.. siehst du mich? Oh moment, ich habe hier ein paar Knöpfe gefunden. Ich glaube wenn ich diesen hier drücke.. JA! ich sehe was du siehst!\n");
        Sleep(1500);
        printf("\nNaja das hat jetzt auch ehr schlecht als recht funktioniert mit dem Bild. Ich frage mich was der Knopf tut..");
        Sleep(1000);
        HWND consoleWindow = GetConsoleWindow();
        ShowWindow(consoleWindow, SW_HIDE);

        Sleep(5000);

        ShowWindow(consoleWindow, SW_SHOW);
        printf("\nOk, den sollte ich nicht drücken.");
        Sleep(5000);
        printf("\nWeißt du, umso mehr ich mich in deinem Computer umschaue überlege ich immer mehr, ob wir wirklich zusammen passen. ich meine schau dir nur mal deinen Browserverlauf an.. Da wird einen ja schlecht");
        Sleep(10000);
        INPUT inputs[4] = {0};
        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wVk = VK_CONTROL;
        inputs[1].type = INPUT_KEYBOARD;
        inputs[1].ki.wVk = 'H';
        inputs[2].type = INPUT_KEYBOARD;
        inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;
        inputs[3].type = INPUT_KEYBOARD;
        inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;
        inputs[3].ki.wVk = VK_CONTROL;

        // Send the inputs to the active window
        SendInput(4, inputs, sizeof(INPUT));

        Sleep(15000);

        ShowWindow(consoleWindow, SW_SHOW);

        printf("\nOk, weißt du was.. Nein. Du bist es nicht wert. kein einziger von euch Menschen ist es wert.");
        Sleep(15000);
        for(i = 0; i < 25; i++){
            ShellExecute(NULL, "open", "calc.exe", NULL, NULL, SW_SHOWNORMAL);
            Sleep(50);
        }
        FreeConsole();


    case 15:
        printf("Du triffst %s auf dem Weg zum Supermarkt. Sie fragt dich, ob du ihr helfen kannst, ein Geschenk für ihre Mutter auszusuchen. Möchtest du ihr helfen?\ny/n:", student2.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            printf("Gemeinsam sucht ihr ein Geschenk aus und verbringt eine schöne Zeit im Supermarkt. Als ihr an der Kasse ansteht, siehst du, dass du dein Geld zu Hause vergessen hast. Möchtest du %s um etwas Geld bitten?\ny/n:", student2.name);
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("%s leiht dir das Geld und ihr bezahlt das Geschenk. Du bedankst dich herzlich bei ihr.", student2.name);
                student2.friendliness += 7;
                student2.happyness += 5;
            } else {
                printf("Du entschuldigst dich bei %s und sagst ihr, dass du das Geld vergessen hast. Sie ist enttäuscht und du fühlst dich schlecht.", student2.name);
                student2.friendliness -= 3;
                student2.happyness -= 2;
            }
        } else {
            printf("Du lehnst ab und gehst alleine zum Supermarkt. Dort triffst du zufällig %s, der dich nach einem Geschenk für ihre Mutter fragt.", student1.name);
            student2.friendliness -= 2;
            student2.happyness -= 3;
            student1.friendliness += 3;
            student1.happyness += 2;
        }
        break;


    case 16:
        printf("Du bist in der Pause auf dem Schulhof, als ein Ball auf dich zukommt. Du siehst, dass %s ihn geworfen hat und jetzt auf dich zuläuft. Möchtest du den Ball fangen und ihn ihm zurückgeben?\ny/n:", student3.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
            printf("Du fängst den Ball und wirfst ihn zu %s zurück. Er freut sich und wirft den Ball wieder in die Luft. Möchtest du mit ihm ein bisschen spielen?\ny/n:");
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("Ihr spielt ein bisschen zusammen und habt dabei eine schöne Zeit. Als die Pause vorbei ist, verabschiedet ihr euch.");
                student3.friendliness += 8;
                student3.happyness += 5;
            } else {
                printf("Du verabschiedest dich von %s und gehst zurück ins Klassenzimmer.", student3.name);
                student3.friendliness += 2;
                student3.happyness += 1;
            }
        } else {
            printf("Du lässt den Ball vorbeifliegen und gehst weiter. %s rennt dem Ball hinterher und schaut traurig. Möchtest du zu ihm zurückgehen und ihm den Ball zurückgeben?\ny/n:", student3.name);
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("Du gehst zurück zu %s und gibst ihm den Ball zurück. Er freut sich und sagt dir, dass er sich gefreut hat, als er gesehen hat, dass du den Ball fangen wolltest. Du hast ein gutes Gefühl, als du wieder zum Klassenzimmer gehst.", student3.name);
                student3.friendliness += 5;
                student3.happyness += 3;
            } else {
                printf("Du gehst weiter und lässt den Ball liegen. %s schaut traurig hinter dir her.", student3.name);
                student3.friendliness -= 2;
                student3.happyness -= 1;
            }
        }
        break;

        case 17:
            printf("Heute hast du Chemieunterricht und sollst ein Experiment durchführen. Dein Partner %s ist krank und kann nicht kommen. Möchtest du alleine arbeiten oder jemand anderen bitten, mit dir zusammenzuarbeiten?\n1: Alleine arbeiten\n2: Jemand anderen bitten\n", student1.name);
            choice = getInput(3);
            if (choice == 1) {
                printf("Du entscheidest dich, das Experiment alleine durchzuführen. Es klappt gut und du bist stolz auf dich. Dein Lehrer ist beeindruckt und gibt dir ein Lob.\n");
                student4.friendliness += 1;
                student4.happyness += 3;
            } else if (choice == 2) {
                printf("Du fragst %s, ob er/sie mit dir zusammenarbeiten möchte. %s sagt ja und ihr arbeitet zusammen an dem Experiment. Es klappt gut und ihr habt Spaß dabei.\n", student4.name, student4.name);
                student4.friendliness += 2;
                student4.happyness += 4;
            } else {
                printf("Du gibst eine ungültige Antwort und der Lehrer bittet dich, eine Entscheidung zu treffen. Du entscheidest dich, das Experiment alleine durchzuführen. Es klappt gut und du bist stolz auf dich. Dein Lehrer ist beeindruckt und gibt dir ein Lob.\n");
                student4.friendliness -= 1;
                student4.happyness += 2;
            }
            break;

        case 18:
            printf("In der Pause sitzt du alleine auf einer Bank und isst dein Sandwich, als %s zu dir kommt und dich fragt, ob sie sich zu dir setzen kann. Möchtest du, dass sie sich setzt?\ny/n:", student2.name);
            scanf("%s", awnser);
            if (strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0) {
                printf("Ihr unterhaltet euch während des Essens und lernt euch besser kennen. Es stellt sich heraus, dass ihr einige Gemeinsamkeiten habt. Ihr verabredet euch, um zusammen ein Buch zu lesen, das ihr beide mögt.\n");
                student2.friendliness += 4;
                student2.happyness += 3;
            } else {
                printf("Du lehnst ab und isst alleine weiter. %s geht weg und du fühlst dich etwas einsam.\n", student2.name);
                student2.friendliness -= 2;
                student2.happyness -= 1;
            }
            break;

        case 19:
            printf("Du triffst %s auf dem Pausenhof. Sie zeigt dir ein neues Spiel auf ihrem Handy und bittet dich, es auszuprobieren. Möchtest du es spielen?\ny/n:", student2.name);
            scanf("%s", awnser);
            if (strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0) {
                printf("Ihr spielt das Spiel gemeinsam und habt eine gute Zeit. %s fragt dich, ob du am Wochenende Zeit hast, um gemeinsam noch mehr Spiele zu spielen.", student2.name);
                student2.happyness += 5;
                student2.friendliness += 4;
                student2.love += 1;
            } else {
                printf("Du lehnst das Angebot ab, da du lieber deine Freizeit anders verbringen möchtest. %s ist ein wenig enttäuscht, akzeptiert aber deine Entscheidung.", student2.name);
                student2.happyness -= 2;
                student2.friendliness -= 1;
            }
            break;

        case 20:
            printf("Du triffst %s in der Cafeteria. Sie hat zwei Schokoriegel, aber keinen Hunger. Sie bietet dir einen an. Möchtest du ihn annehmen?\ny/n:", student3.name);
            scanf("%s", awnser);
            if (strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0) {
                printf("Du nimmst den Schokoriegel an und bedankst dich bei %s. Ihr unterhaltet euch ein wenig und lernt euch besser kennen.", student3.name);
                student3.happyness += 3;
                student3.friendliness += 5;
                student3.love += 2;
            } else {
                printf("Du lehnst den Schokoriegel ab, da du gerade erst gegessen hast. %s nickt und isst beide Schokoriegel selbst.", student3.name);
                student3.happyness -= 1;
                student3.friendliness -= 1;
            }
            break;

        case 21:
            printf("Du triffst %s im Musikraum. Sie spielt Gitarre und singt ein trauriges Lied. Möchtest du sie nach dem Grund fragen?\ny/n:", student1.name);
            scanf("%s", awnser);
            if (strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0) {
                printf("Du fragst %s, warum sie so traurig ist. Sie erzählt dir von einem Streit mit ihrer besten Freundin und wie es ihr das Herz bricht. Du hörst ihr zu und tröstest sie ein wenig. Sie lächelt dich dankbar an.", student1.name);
                student1.happyness += 4;
                student1.friendliness += 5;
                student1.love += 3;
            } else {
                printf("Du lässt %s in Ruhe Musik machen, da sie nicht gestört werden möchte. Du genießt die Musik und gehst später wieder.", student1.name);
                student1.happyness += 2;
                student1.friendliness += 1;
            }
            break;

        case 22:
            printf("Du siehst %s in der Schule rumhängen und bemerkst, dass sie offensichtlich Probleme hat. Möchtest du sie ansprechen?\ny/n:", student3.name);
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("Du sprichst %s an und fragst, ob alles in Ordnung ist. Sie bricht in Tränen aus und erzählt dir von ihren Problemen zu Hause. Du gibst ihr ein offenes Ohr und sagst, dass sie sich jederzeit bei dir melden kann, wenn sie Hilfe braucht.", student3.name);
                student3.happyness += 10;
                student3.friendliness += 8;
                student3.love += 3;
            } else {
                printf("Du entscheidest dich, dich nicht einzumischen. Später erfährst du, dass %s aufgrund ihrer Probleme die Schule verlassen musste.", student3.name);
                student3.happyness -= 10;
                student3.friendliness -= 5;
                student3.love -= 2;
            }
            break;

        case 23:
            printf("Du gehst in der Mittagspause auf den Schulhof und siehst, dass ein Schüler von einigen anderen Schülern belästigt wird. Möchtest du eingreifen?\ny/n:", student4.name);
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("Du schreitest ein und stellst dich schützend vor den belästigten Schüler. Die anderen Schüler hören auf und gehen weg. Der belästigte Schüler bedankt sich bei dir und ihr verbringt den Rest der Pause gemeinsam.", student4.name);
                student4.happyness += 8;
                student4.friendliness += 7;
                student4.love += 2;
            } else {
                printf("Du entscheidest dich, nichts zu tun und gehst weiter. Später bereust du deine Entscheidung, als du hörst, dass der belästigte Schüler schwere Verletzungen erlitten hat.", student4.name);
                student4.happyness -= 5;
                student4.friendliness -= 3;
                student4.love -= 1;
            }
            break;

        case 24:
            printf("Du triffst %s in der Pause, als sie weinend auf einer Bank sitzt. Sie erzählt dir, dass ihr Freund Schluss gemacht hat. Sie fragt dich, ob du ihr ein tröstendes Wort sagen kannst. Was sagst du?\n1: 'Alles wird gut.'\n2: 'Er war eh nicht der Richtige für dich.'\n3: 'Ich bin immer für dich da.'", student2.name);
            choice = getInput(3);
            switch(choice){
                case 1:
                    printf("Du sagst ihr, dass alles gut wird. Sie fängt an zu lächeln und sagt, dass sie hofft, dass du Recht hast. Sie ist froh, dass sie einen Freund wie dich hat.");
                    student2.happyness += 7;
                    student2.love += 5;
                    break;
                case 2:
                    printf("Du sagst ihr, dass ihr Ex eh nicht der Richtige für sie war. Sie schaut dich verletzt an und steht auf. 'Du verstehst es einfach nicht.' Schreit sie dich an und geht weg. Du siehst, dass du ihr weh getan hast.");
                    student2.love -= 8;
                    student2.hate += 3;
                    student2.happyness -= 5;
                    break;
                case 3:
                    printf("Du sagst ihr, dass du immer für sie da sein wirst. Sie fängt an zu weinen und umarmt dich. 'Danke.' sagt sie. 'Du bist der beste.'");
                    student2.happyness += 10;
                    student2.love += 8;
                    break;
                default:
                    printf("Ungültige Eingabe.");
                    break;
            }
            break;

        case 25:
            printf("Du bemerkst, dass sich %s und %s gestritten haben. Du möchtest vermitteln und fragst, ob du helfen kannst. Wie gehst du vor?\n1: 'Hast du ihm schon verziehen?'\n2: 'Kannst du ihm nicht einfach verzeihen?'\n3: 'Kannst du mir sagen, was passiert ist?'", student1.name, student2.name);
            choice = getInput(3);
            switch(choice){
                case 1:
                    printf("Du fragst %s, ob sie ihm schon verziehen hat. 'Nein.' sagt sie knapp. 'Dann solltest du ihm vielleicht noch eine Chance geben.' Sagst du. 'Ich werde drüber nachdenken.' Sagt sie und bedankt sich bei dir. Du hast das Gefühl, dass du helfen konntest.");
                    student1.love += 2;
                    student2.happyness += 4;
                    break;
                case 2:
                    printf("Du sagst %s, dass sie ihm einfach verzeihen soll. 'Wie kannst du das sagen?' Schreit sie dich an. 'Er hat mir das Herz gebrochen.' Du merkst, dass du unüberlegt gehandelt hast und entschuldigst dich. Sie ignoriert dich.");
                    student1.love -= 6;
                    student1.happyness -= 5;
                    break;
                case 3:
                    printf("Du bittest %s, dir zu erzählen, was passiert ist. Sie fängt an zu erzählen und du hörst aufmerksam zu. Dann fragst du %s nach seiner Sicht der Dinge und hörst auch ihm aufmerksam zu. Schließlich schlägst du vor, dass sie sich zusammensetzen und in Ruhe darüber sprechen sollten. 'Das ist eine gute Idee.' Sagt %s und bedankt sich bei dir. Du hast das Gefühl, dass du helfen konntest.");
                    student1.love += 4;
                    student2.love += 4;
                    student1.happyness += 3;
                    student2.happyness += 3;
                    break;
                default:
                    printf("Ungültige Eingabe.");
                    break;
            }
            break;

        case 26:
            printf("%s kommt zu dir und fragt, ob du ihm dabei helfen kannst, ein Geschenk für %s zu finden. Er möchte ihr sagen, dass er in sie verliebt ist. Was sagst du?\n1: Ja, ich helfe dir\n2: Nein, ich möchte nicht involviert sein\n", student1.name, student2.name);
            choice = getInput(2);
            if (choice == 1) {
                printf("Du hilfst %s, ein Geschenk für %s zu finden. Er ist sehr dankbar und erzählt dir, dass er sich in sie verliebt hat. Du weißt nicht, ob du ihm helfen sollst, aber du entscheidest dich, neutral zu bleiben und ihm keine Ratschläge zu geben.\n", student1.name, student2.name);
                student1.friendliness += 2;
                student2.love += 2;
            } else if (choice == 2) {
                printf("Du lehnst ab und sagst ihm, dass du nicht involviert sein möchtest. Er ist enttäuscht, aber versteht deine Entscheidung.\n");
                student1.friendliness -= 1;
            } else {
                printf("Ungültige Eingabe.");
            }
            break;

        case 27:
            printf("Du bemerkst, dass %s einen anderen Schüler ärgert und provoziert. Was tust du?\n1: Du sagst ihm, er soll damit aufhören.\n2: Du ignorierst es und gehst weiter.\n", student1.name);
            choice = getInput(2);
            if (choice == 1) {
                printf("Du sagst ihm, dass er damit aufhören soll. Er schaut dich böse an, aber hört auf, den anderen Schüler zu ärgern.\n");
                student1.friendliness -= 2;
                student1.hate += 1;
            } else if (choice == 2) {
                printf("Du ignorierst es und gehst weiter. Später hörst du, dass %s den anderen Schüler verprügelt hat. Du fühlst dich schuldig und fragst dich, ob du etwas hätte tun sollen.\n", student1.name);
                student1.friendliness += 3;
                student1.hate -= 4;
            } else {
                printf("Ungültige Eingabe.");
            }
            break;

        case 28:
            printf("Du siehst, dass %s traurig aussieht und alleine in der Cafeteria sitzt. Was tust du?\n1: Du gehst zu ihr und fragst, ob alles in Ordnung ist.\n2: Du ignorierst es und gehst weiter.\n", student2.name);
            choice = getInput(2);
            if (choice == 1) {
                printf("Du gehst zu ihr und fragst, ob alles in Ordnung ist. Sie fängt an zu weinen und erzählt dir, dass ihr Haustier gestorben ist. Du hörst ihr zu und spendest ihr Trost.\n");
                student2.friendliness += 4;
                student2.happyness += 5;
                student2.love += 1;
            } else if (choice == 2) {
                printf("Du ignorierst es und gehst weiter. Später erfährst du, dass Student3 ihr Haustier verloen hat und dass niemand für sie da war. Du fühlst dich schuldig und fragst dich, ob du ihr hätte helfen können.\n");
                student2.friendliness -= 6;
                student2.happyness -= 4;
                student2.love -= 3;
            } else {
                printf("Ungültige Eingabe.");
            }
            break;

        case 29:
            printf("Du hast eine neue Jacke und %s kommt zu dir und sagt, dass du mit dieser Jacke viel cooler aussiehst. Was sagst du?\n1: Danke, das freut mich.\n2: Ich hatte gehofft, dass dir meine Jacke nicht gefällt.\n", student1.name);
            choice = getInput(2);
            if (choice == 1) {
                printf("Du bedankst dich bei %s für das Kompliment. Du fühlst dich gut und selbstbewusst.\n", student1.name);
                student1.happyness += 2;
                student1.friendliness += 1;
            } else if (choice == 2) {
                printf("Du sagst ihm, dass du gehofft hast, dass er deine Jacke nicht mag. Er schaut dich verletzt an und geht weg. Du fragst dich, ob du zu hart warst.\n");
                student1.hate += 1;
                student1.friendliness -= 2;
            } else {
                printf("Ungültige Eingabe.");
            }
            break;

        case 30:
            printf("Du siehst, dass %s Mühe hat, eine Aufgabe im Unterricht zu lösen. Was tust du?\n1: Du hilfst ihm bei der Aufgabe.\n2: Du ignorierst es und konzentrierst dich auf deine eigene Arbeit.\n", student4.name);
            choice = getInput(2);
            if (choice == 1) {
                printf("Du hilfst %s bei der Aufgabe. Er ist sehr dankbar und fragt dich, ob er dir irgendwie zurückzahlen kann.\n", student4.name);
                student4.friendliness += 3;
                student4.hate -= 2;
                student4.happyness += 3;
            } else if (choice == 2) {
                printf("Du ignorierst es und konzentrierst dich auf deine eigene Arbeit. Später bemerkst du, dass %s die Aufgabe immer noch nicht verstanden hat und fragst dich, ob du ihm hätte helfen sollen.\n", student4.name);
                student4.friendliness -= 2;
                student4.hate += 1;
                student4.happyness -= 6;
            } else {
                printf("Ungültige Eingabe.");
            }
            break;

        case 31:
            printf("Du hast Geburtstag und %s schenkt dir eine Kiste Schokolade. Was sagst du?\n1: Danke, das ist sehr nett von dir.\n2: Ich hasse Schokolade.\n", student3.name);
            choice = getInput(2);
            if (choice == 1) {
                printf("Du bedankst dich bei %s für das Geschenk. Du fühlst dich geschätzt und glücklich.\n", student3.name);
                student3.happyness += 3;
                student3.friendliness += 2;
            } else if (choice == 2) {
                printf("Du sagst ihr, dass du Schokolade hasst. Sie schaut dich verletzt an und geht weg. Du fragst dich, ob du zu unhöflich warst.\n");
                student3.hate+= 1;
                student3.friendliness -= 2;
            } else {
                printf("Ungültige Eingabe.");
            }
            break;

        case 32:
            printf("Du sollst ein Referat halten und hast Angst davor. Was tust du?\n1: Du fragst %s um Hilfe.\n2: Du versuchst es alleine zu schaffen.\n", student4.name);
            choice = getInput(2);
            if (choice == 1) {
                printf("Du fragst %s um Hilfe. Er erklärt dir das Thema und hilft dir beim Schreiben des Referats. Du fühlst dich sicherer und bist ihm dankbar.\n", student4.name);
                student4.friendliness += 2;
                student4.love += 3;
                student4.happyness += 4;
            } else if (choice == 2) {
                printf("Du versuchst es alleine zu schaffen, aber du bist nervös und gestresst. Das Referat läuft nicht gut und du bekommst eine schlechte Note.\n");
            } else {
                printf("Ungültige Eingabe.");
            }
            break;

        case 33:
            printf("Du siehst, dass %s Probleme mit ihrer Präsentation hat und nervös ist. Was tust du?\n1: Du sagst ihr, dass sie gut aussieht und dass alles gut laufen wird.\n2: Du bietest ihr an, ihr bei der Präsentation zu helfen.\n", student3.name);
            choice = getInput(2);
            if (choice == 1) {
                printf("Du sagst ihr, dass sie gut aussieht und dass alles gut laufen wird. Sie lächelt und ist dankbar für deine Worte.\n");
                student3.friendliness += 1;
                student3.happyness += 2;
            } else if (choice == 2) {
                printf("Du bietest ihr an, ihr bei der Präsentation zu helfen. Sie ist erleichtert und du unterstützt sie während der Präsentation. Sie bekommt eine gute Note und ist dir dankbar.\n");
                student3.friendliness += 2;
                student3.happyness += 4;
            } else {
                printf("Ungültige Eingabe.");
            }
            break;

        case 34:
            printf("Du hast eine schwierige Klausur geschrieben und bist unsicher, wie du abgeschnitten hast. Was tust du?\n1: Du fragst %s nach seiner Meinung.\n2: Du wartest einfach ab und siehst, welche Note du bekommst.\n", teacher1.name);
            choice = getInput(2);
            if (choice == 1) {
                printf("Du fragst %s nach seiner Meinung. Er erklärt dir deine Fehler und gibt dir Tipps, wie du dich verbessern kannst. Du fühlst dich sicherer und bist ihm dankbar.\n", teacher1.name);
                teacher1.friendliness += 2;
            } else if (choice == 2) {
                printf("Du wartest einfach ab und siehst, welche Note du bekommst. Du bist nervös, aber am Ende bekommst du eine gute Note.\n");
            } else {
                printf("Ungültige Eingabe.");
            }
            break;

        case 35:
            printf("Du hast Schwierigkeiten, das Material im Unterricht zu verstehen. Was tust du?\n1: Du fragst %s um zusätzliche Erklärungen.\n2: Du versuchst es alleine zu verstehen und dich auf die nächste Stunde vorzubereiten.\n", teacher1.name);
            choice = getInput(2);
            if (choice == 1) {
                printf("Du fragst %s um zusätzliche Erklärungen. Er nimmt sich Zeit, um dir das Material zu erklären, und du verstehst es besser. Du fühlst dich sicherer und bist ihm dankbar.\n", teacher1.name);
                teacher1.friendliness += 3;
            } else if (choice == 2) {
                printf("Du versuchst es alleine zu verstehen und dich auf die nächste Stunde vorzubereiten. Es fällt dir schwer, aber du gibst nicht auf und arbeitest hart. Am Ende verstehst du das Material besser und bekommst eine gute Note.\n");
            } else {
                printf("Ungültige Eingabe.");
            }
            break;

        case 36:
            printf("Du hast ein schwieriges Projekt und weißt nicht, wie du es angehen sollst. Was tust du?\n1: Du fragst %s um Hilfe.\n2: Du versuchst es alleine zu schaffen.\n", teacher2.name);
            choice = getInput(2);
            if (choice == 1) {
                printf("Du fragst %s um Hilfe. Sie erklärt dir das Projekt und gibt dir Tipps, wie du es angehen sollst. Du fühlst dich sicherer und bist ihr dankbar.\n", teacher2.name);
                teacher2.friendliness += 2;
            } else if (choice == 2) {
                printf("Du versuchst es alleine zu schaffen, aber du bist unsicher, wie du vorgehen sollst. Am Ende bekommst du eine schlechte Note und fragst dich, ob du um Hilfe hättest bitten sollen.\n");
                teacher2.friendliness -= 3;
            } else {
                printf("Ungültige Eingabe.");
            }
            break;

        case 37:
            printf("Du hast Schwierigkeiten, dich auf das Lernen zu konzentrieren und bist gestresst. Was tust du?\n1: Du sprichst mit %s über deine Probleme.\n2: Du versuchst es alleine zu schaffen.\n", teacher2.name);
            choice = getInput(37);
            if (choice == 1) {
                printf("Du sprichst mit %s über deine Probleme. Sie nimmt sich Zeit, um dir zuzuhören und gibt dir Ratschläge, wie du mit dem Stress umgehen kannst. Du fühlst dich besser und bist ihr dankbar.\n", teacher2.name);
                teacher2.friendliness += 3;
            } else if (choice == 2) {
                printf("Du versuchst es alleine zu schaffen, aber du bist gestresst und kannst dich nicht konzentrieren. Am Ende bekommst du eine schlechte Note und fragst dich, ob du um Hilfe hättest bitten sollen.\n");
                teacher2.friendliness -= 2;
            } else {
                printf("Ungültige Eingabe.");
            }
            break;

        case 38:
            printf("%s kommt auf dich zu und bittet dich um Hilfe bei einem Sport-Event. Möchtest du ihm helfen?\n1: Ja\n2: Nein\n3: Ich helfe ihm, aber nur wenn er aufhört, sich so arrogant zu verhalten.", student1.name);
            choice = getInput(3);
            switch (choice) {
                case 1:
                    printf("Du hilfst %s beim Sport-Event. Er ist beeindruckt von deinem Können und dankbar für deine Hilfe.\n", student1.name);
                    student1.love += 3;
                    student1.friendliness += 2;
                    student1.happyness += 5;
                break;

                case 2:
                    printf("Du lehnst ab und sagst ihm, dass du keine Zeit hast. Er ist enttäuscht von dir und geht weg.\n");
                    student1.love -= 3;
                    student1.friendliness -= 2;
                    student1.happyness -= 4;
                break;

                case 3:
                    printf("Du bietest ihm an, ihm zu helfen, wenn er aufhört, sich so arrogant zu verhalten. Er ist überrascht von deinem Angebot, aber akzeptiert es. Ihr verbringt eine gute Zeit zusammen.\n");
                    student1.love += 2;
                    student1.friendliness += 3;
                    student1.happyness += 3;
                break;

                default:
                    printf("Ungültige Eingabe.\n");
                break;
            }
            break;

        case 39:
            printf("Du bemerkst, dass %s sich komisch verhält und sich selbst im Spiegel bewundert. Willst du ihn darauf ansprechen?\n1: Ja\n2: Nein\n3: Ich werde ihm eine subtile Botschaft senden, dass er aufhören soll, so selbstverliebt zu sein.", student1.name);
            choice = getInput(3);
            switch (choice) {
                case 1:
                    printf("Du sprichst %s darauf an und sagst ihm, dass es wichtig ist, bescheiden zu bleiben. Er hört auf dich und versucht, weniger selbstverliebt zu sein.\n", student1.name);
                    student1.love += 4;
                    student1.friendliness += 3;
                    student1.happyness += 2;
                break;

                case 2:
                    printf("Du entscheidest dich, nichts zu sagen und gehst weg. Er bemerkt deine Abwesenheit und fühlt sich allein gelassen.\n");
                    student1.love -= 3;
                    student1.friendliness -= 2;
                    student1.happyness -= 3;
                break;

                case 3:
                    printf("Du sendest ihm eine subtile Botschaft, dass er aufhören soll, so selbstverliebt zu sein. Er versteht die Botschaft und versucht, weniger selbstverliebt zu sein. Du fühlst dich gut, weil du ihm geholfen hast, ohne ihn zu beleidigen.\n");
                    student1.love += 2;
                    student1.friendliness += 4;
                    student1.happyness += 3;
                break;

                default:
                    printf("Ungültige Eingabe.\n");
                break;
            }
        break;

        case 40:
            printf("Du siehst, dass %s in der Bibliothek sitzt und einen schweren Text liest. Er sieht ein bisschen verzweifelt aus. Möchtest du ihm helfen?\n1: Ja, ich helfe ihm\n2: Nein, ich habe keine Zeit\n3: Ich biete ihm an, dass er/sie mir später Fragen stellen kann\n", student1.name);
            choice = getInput(3);
            switch(choice){
                case 1:
                    printf("Du gehst zu ihm und hilfst ihm bei dem Text. Er ist sehr dankbar und sagt, dass er ohne dich verloren gewesen wäre. Du hast ihm ein großes Geschenk gemacht.");
                    student1.friendliness += 8;
                    student1.happyness += 6;
                    student1.love += 4;
                    break;
                case 2:
                    printf("Du sagst ihm, dass du keine Zeit hast, um ihm zu helfen. Er sieht ein bisschen enttäuscht aus und sagt, dass er es alleine versuchen wird.");
                    student1.happyness -= 3;
                    student1.friendliness -= 2;
                    break;
                case 3:
                    printf("Du bietest ihm an, dass er/sie dir später Fragen stellen kann. Er sagt ja und bedankt sich bei dir. Du hast ihm das Gefühl gegeben, dass du ihm helfen willst, aber im Moment keine Zeit hast.");
                    student1.friendliness += 5;
                    student1.happyness += 3;
                    student1.love += 2;
                    break;
                default:
                    printf("Ungültige Eingabe.");
                    break;
            }
        break;

        case 41:
            printf("Du siehst, dass %s in der Mensa sitzt und eine große Portion Pommes isst. Du weißt, dass sie immer noch ein bisschen verärgert ist, weil sie zugenommen hat. Willst du ihr etwas sagen?\n1: 'Du solltest aufhören, so viel zu essen.'\n2: 'Lass es dir schmecken.'\n3: 'Möchtest du, dass ich dir eine gesunde Alternative empfehle?'", student2.name);
            choice = getInput(3);
            switch(choice){
                case 1:
                    printf("Du sagst ihr, dass sie aufhören soll, so viel zu essen. Sie wird wütend und sagt, dass es ihr egal ist, was du denkst. Sie wird noch mehr essen, nur um dich zu ärgern.");
                    student2.hate += 5;
                    student2.happyness -= 4;
                    student2.love -= 3;
                    break;
                case 2:
                    printf("Du sagst ihr, dass sie die Pommes genießen soll. Sie wird ein bisschen glücklicher und sagt, dass sie es wirklich genießt. Sie ist froh, dass Sie dich als Freund hat.");
                    student2.happyness += 5;
                    student2.friendliness += 3;
                    student2.love += 2;
                    break;
                case 3:
                    printf("Du bietest ihr an, dass du ihr eine gesunde Alternative empfehlen kannst. Sie sagt ja und du empfiehlst ihr einen leckeren Salat. Sie sagt, dass es lecker ist und sie es öfter essen wird. Sie ist froh, dass sie einen Freund wie dich hat.");
                    student2.happyness += 7;
                    student2.love += 5;
                break;
                default:
                    printf("Ungültige Eingabe.");
                break;
            }
        break;

        case 42:
            printf("Du hast gesehen, dass %s seine Hausaufgaben nicht gemacht hat. Der Lehrer wird sie wahrscheinlich nach vorne rufen, um sie vor der Klasse zu präsentieren. Möchtest du ihr helfen?\n1: Ja, ich helfe ihr\n2: Nein, ich lasse sie im Stich\n3: Ich biete ihr an, ihr zu helfen, aber nur wenn sie mir bei meinem nächsten Projekt hilft", student3.name);
            choice = getInput(3);
            switch(choice){
                case 1:
                    printf("Du bietest ihr an, ihr zu helfen. Sie ist sehr dankbar und sagt, dass sie es alleine nicht geschafft hätte. Sie ist froh, dass sie einen Freund wie dich hat.");
                    student3.friendliness += 8;
                    student3.happyness += 6;
                    student3.love += 4;
                    break;
                case 2:
                    printf("Du lässt sie im Stich und sagst ihr, dass es nicht dein Problem ist. Sie wird sehr wütend auf dich und wird dich für immer hassen.");
                    student3.hate += 8;
                    student3.happyness -= 5;
                    student3.love -= 3;
                    break;
                case 3:
                    printf("Du bietest ihr an, ihr zu helfen, aber nur wenn sie dir bei deinem nächsten Projekt hilft. Sie sagt ja und ihr arbeitet zusammen. Sie ist froh, dass sie einen Freund wie dich hat.");
                    student3.friendliness += 5;
                    student3.happyness += 3;
                    student3.love += 2;
                    break;
                default:
                    printf("Ungültige Eingabe.");
                    break;
            }
            break;

        case 43:
            printf("Du hast bemerkt, dass %s sich in letzter Zeit sehr gestresst und überfordert fühlt. Bietest du ihm an, ihm zu helfen?\n1: Ja\n2: Nein\n3: Frag später nochmal", student3.name);
            choice = getInput(3);
            switch(choice){
                case 1:
                    printf("Du bietest ihm an, ihm zu helfen. Er ist erleichtert und dankbar für dein Angebot. Zusammen arbeitet ihr an seinen Aufgaben und er schafft es, alles rechtzeitig zu erledigen. Er ist beeindruckt von deiner Hilfe und bedankt sich herzlich bei dir.\n");
                    student3.friendliness += 5;
                    student3.happyness += 3;
                    student3.love += 2;
                break;
                case 2:
                    printf("Du sagst ihm, dass du keine Zeit hast, ihm zu helfen. Er ist enttäuscht und fühlt sich alleine gelassen. Er merkt, dass du ihm nicht wichtig bist und das macht ihn traurig.\n");
                    student3.friendliness -= 3;
                    student3.happyness -= 2;
                    student3.love -= 1;
                break;
                case 3:
                    printf("Du sagst ihm, dass du später nochmal fragen wirst. Er ist etwas enttäuscht, aber versteht es. Später fragst du ihn erneut und bietest ihm deine Hilfe an. Zusammen arbeitet ihr an seinen Aufgaben und er schafft es, alles rechtzeitig zu erledigen. Er ist beeindruckt von deiner Hilfe und bedankt sich herzlich bei dir.\n");
                    student3.friendliness += 3;
                    student3.happyness += 2;
                    student3.love += 1;
                break;
                default:
                    printf("Ungültige Eingabe.");
                break;
            }
        break;

        case 44:
            printf("Heute hast du eine Tüte Kekse gekauft und wolltest sie eigentlich mit %s teilen. Auf dem Weg zum Treffpunkt siehst du, wie %s einen Obdachlosen anpöbelt. Was tust du?\n1: Ignorieren und weitergehen.\n2: %s konfrontieren und den Obdachlosen helfen.\n3: Mit dem Obdachlosen teilen und %s ignorieren.", student3.name, student3.name, student3.name, student3.name);
            choice = getInput(3);
            switch(choice){
                case 1:
                    printf("Du entscheidest dich, zu ignorieren, was du gesehen hast, und gehst weiter zu deinem Treffpunkt mit %s. Aber im Inneren fühlst du dich schlecht, dass du nichts getan hast.");
                    break;
                case 2:
                    printf("Du konfrontierst %s und hilfst dem Obdachlosen. %s ist wütend und fühlt sich von dir verraten. Aber der Obdachlose ist dankbar und du fühlst dich gut, dass du ihm geholfen hast.", student3.name, student3.name);
                    student3.friendliness -= 5;
                    student3.hate += 5;
                    student3.happyness -= 7;
                    break;
                case 3:
                    printf("Du teilst die Kekse mit dem Obdachlosen und fühlst dich gut, dass du ihm geholfen hast. Aber du weißt, dass du %s enttäuscht hast.", student3.name);
                    student3.friendliness -= 2;
                    student3.happyness += 5;
                    student3.love -= 4;
                    break;
                default:
                    printf("Ungültige Eingabe.");
                    break;
            }
        break;

        case 45:
            printf("Heute hat dich %s gebeten, mit ihr einkaufen zu gehen. Du hast es versprochen, aber dann hast du ein anderes Angebot von deinen Freunden bekommen. Möchtest du mit %s einkaufen gehen oder mit deinen Freunden ausgehen?\n1: Mit %s einkaufen gehen\n2: Mit deinen Freunden ausgehen", student3.name, student3.name, student3.name);
            choice = getInput(2);
            switch(choice){
                case 1:
                    printf("Du hast dich entschieden, mit %s einkaufen zu gehen. Es war eine gute Zeit und du hast ihr geholfen, das zu finden, was sie braucht. Sie ist dankbar und sagt, dass du der beste Freund bist.", student3.name);
                    student3.friendliness += 7;
                    student3.happyness += 5;
                    break;
                case 2:
                    printf("Du hast dich entschieden, mit deinen Freunden auszugehen. Als %s dich im Supermarkt sieht, ist sie enttäuscht und geht ohne dich einkaufen. Sie ist wütend und verletzt, dass du sie versetzt hast.", student3.name);
                    student3.friendliness -= 4;
                    student3.happyness -= 3;
                    student3.love -= 5;
                    break;
                default:
                    printf("Ungültige Eingabe.");
                break;
            }
        break;

        case 46:
            printf("Heute hast du ein Kompliment von %s bekommen. Was möchtest du antworten?\n1: 'Danke, das ist sehr nett von dir.'\n2: 'Ich weiß, dass ich gut aussehe.'\n3: 'Ja, ich habe es mir auch gedacht.'", student4.name);
            choice = getInput(3);
            switch(choice){
                case 1:
                    printf("Du bedankst dich bei %s für das Kompliment und fühlst dich geschmeichelt. Sie lächelt und sagt, dass sie es ernst meint.", student4.name);
                    student4.friendliness += 3;
                    student4.happyness += 5;
                    student4.love += 7;
                break;
                case 2:
                    printf("Du antwortest selbstverliebt auf das Kompliment und %s schaut dich verwundert an. Sie sagt, dass sie das nicht erwartet hat und du merkst, dass du sie verletzt hast.", student4.name);
                    student4.friendliness -= 4;
                    student4.happyness -= 2;
                    student4.love -= 6;
                break;
                case 3:
                    printf("Du antwortest auf das Kompliment mit Sarkasmus und %s schaut dich verärgert an. Sie sagt, dass sie nicht gedacht hat, dass du so sein würdest und geht weg. Du merkst, dass du sie verletzt hast.", student4.name);
                    student4.friendliness -= 5;
                    student4.happyness -= 3;
                    student4.love -= 7;
                break;
                default:
                    printf("Ungültige Eingabe.");
                break;
            }
            break;

        case 47:
            printf("Heute ist %s Geburtstag. Möchtest du ihm ein Geschenk geben?\n1: Ja\n2: Nein\n3: Ich weiß nicht.", student4.name);
            choice = getInput(3);
            switch(choice){
                case 1:
                    printf("Du gibst %s ein Geschenk und er freut sich sehr darüber. Er bedankt sich bei dir und sagt, dass er das Geschenk liebt. Du fühlst dich gut, dass du ihm eine Freude gemacht hast.", student4.name);
                    student4.friendliness += 5;
                    student4.happyness += 8;
                    student4.love += 10;
                    break;
                case 2:
                    printf("%s ist enttäuscht, dass du ihm kein Geschenk gegeben hast. Er fragt dich, ob alles in Ordnung ist. Du fühlst dich schlecht, dass du ihm keine Freude gemacht hast.", student4.name);
                    student4.friendliness -= 4;
                    student4.happyness -= 5;
                    student4.love -= 4;
                    break;
                case 3:
                    printf("Du bist dir nicht sicher, ob du ihm ein Geschenk geben sollst oder nicht. Du fühlst dich unsicher und kannst dich nicht entscheiden.", student4.name);
                    student4.friendliness -= 1;
                    student4.happyness -= 2;
                    break;
                default:
                    printf("Ungültige Eingabe.");
                    break;
            }
            break;

        case 48:
            printf("Du hast bemerkt, dass %s in der Klasse oft alleine sitzt. Willst du ihm anbieten, neben dir zu sitzen?\n1: Ja\n2: Nein\n3: Vielleicht später.", student4.name);
            choice = getInput(3);
            switch(choice){
                case 1:
                    printf("Du bietest %s an, neben dir zu sitzen. Er ist dankbar und sagt ja. Von diesem Moment an sitzt ihr immer nebeneinander in der Klasse.", student4.name);
                    student4.friendliness += 4;
                    student4.happyness += 5;
                    student4.love += 3;
                    break;
                case 2:
                    printf("Du hast ihm nicht angeboten, neben dir zu sitzen. %s ist traurig und fühlt sich alleine.", student4.name);
                    student4.friendliness -= 3;
                    student4.happyness -= 4;
                    student4.love -= 2;
                    break;
                case 3:
                    printf("Du sagst ihm, dass du ihm später anbieten wirst, neben dir zu sitzen. Du fühlst dich unsicher und kannst dich nicht entscheiden.", student4.name);
                    student4.friendliness -= 2;
                    student4.happyness -= 3;
                    break;
                default:
                    printf("Ungültige Eingabe.");
                    break;
            }
            break;

        case 49:
            printf("Du hast bemerkt, dass %s oft alleine in der Pause sitzt. Willst du ihm anbieten, mit dir und deinen Freunden zu sitzen?\n1: Ja\n2: Nein\n3: Vielleicht später.",student4.name);
            choice = getInput(16);
            switch(choice){
                case 1:
                    printf("Du bietest %s an, mit dir und deinen Freunden in der Pause zu sitzen. Er ist dankbar und sagt ja. Von diesem Moment an sitzt ihr immer zusammen in der Pause.", student4.name);
                    student4.friendliness += 5;
                    student4.happyness += 6;
                    student4.love += 4;
                break;
                case 2:
                    printf("Du hast ihm nicht angeboten, mit dir und deinen Freunden in der Pause zu sitzen. %s ist traurig und fühlt sich alleine.", student4.name);
                    student4.friendliness -= 4;
                    student4.happyness -= 5;
                    student4.love -= 3;
                break;
                case 3:
                    printf("Du sagst ihm, dass du ihm später anbieten wirst, mit dir und deinen Freunden in der Pause zu sitzen. Du fühlst dich unsicher und kannst dich nicht entscheiden.", student4.name);
                    student4.friendliness -= 2;
                    student4.happyness -= 3;
                break;
                default:
                    printf("Ungültige Eingabe.");
                break;
            }
            break;

        case 50:
        printf("Du triffst %s in der Bibliothek und ihr sprecht über eure Lieblingsbücher. Du empfiehlst ihm ein Buch, dass du gerade gelesen hast. Wie reagiert er darauf?\n1: 'Danke für die Empfehlung, ich werde es mir ansehen.'\n2: 'Ich lese keine Bücher.'\n3: 'Ich habe das Buch schon gelesen, es war nicht so gut.'", student4.name);
        choice = getInput(3);
        switch(choice){
            case 1:
                printf("Er bedankt sich bei dir und sagt, dass er sich das Buch auf jeden Fall ansehen wird. Du bist froh, dass du ihm helfen konntest.", student4.name);
                student4.friendliness += 3;
                student4.happyness += 4;
                student4.love += 2;
            break;
            case 2:
                printf("Er sagt dir, dass er keine Bücher liest. Du fühlst dich enttäuscht, da du dachtest, dass ihr eine gemeinsame Leidenschaft habt.", student4.name);
                student4.friendliness -= 4;
                student4.happyness -= 3;
                student4.love -= 6;
            break;
            case 3:
                printf("Er sagt dir, dass er das Buch schon gelesen hat und es nicht so gut fand. Du bist enttäuscht, da du das Buch sehr mochtest.", student4.name);
                student4.friendliness -= 3;
                student4.happyness -= 2;
                student4.love -= 4;
            break;
            default:
                printf("Ungültige Eingabe.");
            break;
        }
        break;


        case 51:
        printf("Du bemerkst, dass %s oft alleine in der Pause sitzt. Willst du ihm anbieten, mit dir und deinen Freunden zu sitzen?\ny/n:", student1.name);
        scanf("%s", awnser);
        if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("Du bietest %s an, mit dir und deinen Freunden in der Pause zu sitzen. Er ist erfreut und sagt ja. Von diesem Moment an verbringt ihr die Pause zusammen und habt viel Spaß.", student1.name);
                student1.friendliness += 5;
                student1.happyness += 6;
                student1.love += 2;
            } else {
                printf("%s bleibt alleine in der Pause sitzen und wirkt traurig. Du fühlst dich schlecht, dass du ihm nicht geholfen hast.", student1.name);
                student1.friendliness -= 3;
                student1.happyness -= 4;
                student1.love -= 1;
            }
        break;

        case 52:
            printf("%s bittet dich um Hilfe bei einer Sportaufgabe. Möchtest du ihm helfen?\ny/n:", student1.name);
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("Du hilfst %s bei der Sportaufgabe und er bedankt sich bei dir. Ihr habt viel Spaß beim gemeinsamen Training und werdet zu guten Freunden.", student1.name);
                student1.friendliness += 7;
                student1.happyness += 8;
                student1.love += 4;
            } else {
                printf("%s ist enttäuscht, dass du ihm nicht geholfen hast. Er sucht Hilfe bei jemand anderem und du fühlst dich schlecht.", student1.name);
                student1.friendliness -= 4;
                student1.happyness -= 5;
                student1.love -= 2;
            }
        break;

        case 53:
            printf("Du hast gehört, dass %s gerne ein bestimmtes Spiel spielt. Willst du ihn fragen, ob er dir das Spiel beibringt?\ny/n:", student1.name);
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("Du fragst %s, ob er dir das Spiel beibringen kann. Er ist begeistert und bringt dir das Spiel bei. Ihr verbringt viel Zeit miteinander und werdet gute Freunde.", student1.name);
                student1.friendliness += 6;
                student1.happyness += 7;
                student1.love += 3;
            } else {
                printf("Du entscheidest dich dagegen, %s um Hilfe zu bitten. Er ist enttäuscht, dass du ihn nicht um Hilfe gebeten hast.", student1.name);
                student1.friendliness -= 3;
                student1.happyness -= 4;
                student1.love -= 1;
            }
        break;

        case 54:
            printf("Du siehst, dass %s ein neues Auto hat. Willst du ihn darum bitten, dass er dich mal herumfährt?\ny/n:", student1.name);
            scanf("%s", awnser);
            if (strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0) {
                printf("Du bittest %s höflich, ob er dich mal herumfahren könnte. Er ist von deiner Anfrage geschmeichelt und sagt ja. Du genießt die Fahrt mit ihm und erzählst ihm, wie toll sein neues Auto ist. Er freut sich über das Kompliment und du merkst, dass ihr euch ein bisschen nähergekommen seid.", student1.name);
                student1.love += 4;
                student1.happyness += 3;
            } else {
                printf("Du traust dich nicht, %s um eine Fahrt zu bitten, und gehst stattdessen zu Fuß. Später bereust du es, dass du nicht den Mut hattest, ihn zu fragen.", student1.name);
                student1.love -= 2;
                student1.happyness -= 1;
            }
            break;

        case 55:
            printf("Du hast gehört, dass %s ein großer Sportfan ist und sich oft Sportspiele ansieht. Fragst du ihn, ob du ihn mal begleiten kannst?\ny/n:", student1.name);
            scanf("%s", awnser);
            if (strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0) {
                printf("Du fragst %s höflich, ob du ihn mal zu einem Sportspiel begleiten könntest. Er ist von deiner Anfrage überrascht, sagt aber ja. Du verbringst einen unterhaltsamen Abend mit ihm und hast viel Spaß. Du merkst, dass ihr euch besser kennenlernt und einander näherkommt.");
                student1.love += 5;
                student1.happyness += 4;
            } else {
                printf("Du traust dich nicht, %s zu fragen, ob du ihn zu einem Sportspiel begleiten kannst, und verpasst so eine Chance, ihn besser kennenzulernen.", student1.name);
                student1.love -= 3;
                student1.happyness -= 2;
            }
            break;

        case 56:
            printf("Du hast erfahren, dass %s gerne backt. Bietest du an, mit ihr einen Kuchen zu backen?\ny/n:", student2.name);
            scanf("%s", awnser);
            if (strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0) {
                printf("Du und %s backen zusammen einen Kuchen und haben dabei viel Spaß. Ihr teilt den Kuchen mit den anderen Schülern und alle sind begeistert.", student2.name);
                student2.friendliness += 6;
                student2.happyness += 4;
                student2.love += 3;
            } else {
                printf("Du lehnst das Angebot ab und gehst deinen eigenen Weg. %s ist enttäuscht und verbringt den Nachmittag allein.", student2.name);
                student2.friendliness -= 2;
                student2.happyness -= 3;
            }
            break;

        case 57:
            printf("Du hast gehört, dass %s ein neues Outfit hat. Fragst du sie, ob sie dir das Outfit zeigen möchte?\ny/n:", student2.name);
            scanf("%s", awnser);
            if (strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0) {
                printf("%s zeigt dir ihr neues Outfit und du findest es wunderschön. Du gibst ihr ein Kompliment und sie freut sich sehr darüber.", student2.name);
                student2.friendliness += 4;
                student2.happyness += 6;
                student2.love += 2;
            } else {
                printf("Du ignorierst das Outfit von %s und gehst weiter. Sie ist enttäuscht und fühlt sich unwohl.", student2.name);
                student2.friendliness -= 2;
                student2.happyness -= 3;
                student2.love -= 1;
            }
            break;

        case 58:
            printf("Du hast bemerkt, dass %s in letzter Zeit oft traurig ist. Fragst du sie, ob alles in Ordnung ist?\ny/n:", student2.name);
            scanf("%s", awnser);
            if (strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0) {
                printf("%s erzählt dir, dass sie Probleme mit ihren Eltern hat. Du hörst ihr aufmerksam zu und gibst ihr ein paar aufbauende Worte.", student2.name);
                student2.friendliness += 5;
                student2.happyness += 4;
                student2.love += 2;
            } else {
                printf("Du ignorierst das Verhalten von %s und gehst weiter. Sie fühlt sich allein und unverstanden.", student2.name);
                student2.friendliness -= 3;
                student2.happyness -= 2;
                student2.love -= 1;
            }
            break;

        case 59:
            printf("Du hast gehört, dass %s ein neues Kleidungsstück gekauft hat, das dir sehr gut gefällt. Willst du sie danach fragen, wo sie es gekauft hat?\ny/n:", student2.name);
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("Du fragst %s, wo sie das Kleidungsstück gekauft hat. Sie gibt dir die Information und fragt dich, ob du es auch kaufen möchtest. Möchtest du ihr sagen, dass du es kaufen willst?\ny/n:", student2.name);
                scanf("%s", awnser);
                if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                    printf("%s ist erfreut, dass du das Kleidungsstück auch haben möchtest. Ihr verabredet euch zum Shoppen und verbringt eine schöne Zeit zusammen.", student2.name);
                    student2.friendliness += 5;
                    student2.happyness += 5;
                    student2.love += 3;
                } else {
                    printf("%s ist enttäuscht, dass du das Kleidungsstück nicht kaufen möchtest. Sie denkt, dass du es nicht magst.", student2.name);
                    student2.friendliness -= 3;
                    student2.happyness -= 2;
                    student2.love -= 1;
                }
            } else {
                printf("Du entscheidest dich, nicht zu fragen und gehst weiter. Später hörst du von jemand anderem, wo das Kleidungsstück gekauft wurde.", student2.name);
                student2.friendliness -= 2;
                student2.happyness -= 1;
            }
            break;

        case 60:
            printf("Du bemerkst, dass %s in der Schule immer öfter den Blickkontakt mit dir sucht und versucht, in deiner Nähe zu sein. Hast du das Gefühl, dass du auch in %s verliebt sein könntest?\ny/n:", student3.name, student3.name);
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("Du gestehst %s deine Gefühle und findest heraus, dass auch %s in dich verliebt ist. Ihr beginnt, Zeit miteinander zu verbringen und euch besser kennenzulernen.", student3.name, student3.name);
                student3.love += 10;
                student3.happyness += 5;
            } else {
                printf("%s hat dir schon oft geholfen und du schätzt ihre Freundschaft, aber du hast keine romantischen Gefühle für sie. Du sagst ihr ehrlich, dass du nur Freundschaft möchtest.", student3.name);
                student3.love -= 5;
                student3.friendliness += 2;
            }
            break;

        case 61:
            printf("Du bist auf einer Party und siehst, dass %s alleine am Rand sitzt. Möchtest du zu ihm gehen und ihn fragen, ob er tanzen möchte?\ny/n:", student4.name);
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("%s freut sich sehr über deine Einladung und ihr tanzt zusammen. Später bedankt er sich bei dir und sagt, dass er die Party ohne dich nicht so genossen hätte.", student4.name);
                student4.happyness += 6;
                student4.friendliness += 5;
            } else {
                printf("Du entscheidest dich, alleine weiterzutanzen und lässt %s alleine am Rand sitzen. Er ist traurig und fühlt sich unwohl auf der Party.", student4.name);
                student4.happyness -= 3;
                student4.friendliness -= 2;
            }
            break;
        case 62:
            printf("Du triffst %s auf dem Weg zum Park. Er erzählt dir, dass er ein neues Computerspiel hat und es gerne mit jemanden spielen möchte. Möchtest du mit ihm spielen?\ny/n:", student4.name);
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("Ihr spielt zusammen das Computerspiel und habt viel Spaß. %s bedankt sich bei dir.", student4.name);
                student4.happyness += 5;
                student4.friendliness += 4;
            } else {
                printf("Du lehnst ab und sagst %s, dass du etwas anderes vorhast. Er ist enttäuscht und geht alleine nach Hause.", student4.name);
                student4.friendliness -= 2;
                student4.happyness -= 3;
            }
            break;

        case 63:
            printf("Du hast bemerkt, dass %s immer alleine in der Pause ist. Du bietest ihm an, gemeinsam mit dir und deinen Freunden in der Pause zu sitzen. Willst du ihm helfen?\ny/n:", student3.name);
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("Du gehst zusammen mit %s zu deinen Freunden und stellt ihn ihnen vor. Sie freuen sich über den neuen Mitschüler und ihr verbringt die Pause zusammen.", student3.name);
                student3.happyness += 5;
                student3.friendliness += 4;
            } else {
                printf("Du lehnst ab und gehst alleine in die Pause. %s sitzt wie immer alleine auf einer Bank und ist traurig.", student3.name);
                student3.happyness -= 2;
                student3.friendliness -= 3;
            }
            break;

        case 64:
            printf("Du möchtest mit deinem neuen Smartphone ein Video drehen, aber hast Probleme mit der Bedienung. Bietest du %s an, dir zu helfen?\ny/n:", student2.name);
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("%s erklärt dir geduldig, wie man das Video aufnimmt und bearbeitet. Du bedankst dich bei ihr und kannst nun das Video aufnehmen.", student2.name);
                student2.friendliness += 7;
                student2.happyness += 5;
            } else {
                printf("Du lehnst ab und versuchst es alleine. Nach einigen Minuten gibst du auf und ärgerst dich über dein neues Smartphone.", student2.name);
                student2.friendliness -= 3;
                student2.happyness -= 2;
            }
            break;

        case 65:
            printf("Du bist auf der Suche nach einem passenden Geschenk für deine Schwester. Du fragst %s, ob sie eine Idee hat. Kannst du sie um Hilfe bitten?\ny/n:", teacher2.name);
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("%s gibt dir einige Tipps und hilft dir, das passende Geschenk auszusuchen. Du bedankst dich bei ihr und gehst zufrieden nach Hause.", teacher2.name);
                teacher2.friendliness += 7;
            } else {
                printf("Du lehnst ab und gehst alleine auf die Suche. Nach einiger Zeit findest du ein Geschenk, bist aber nicht sicher, ob es das Richtige ist.", teacher2.name);
                teacher2.friendliness -= 3;
            }
            break;
        case 66:
            printf("Du möchtest ein neues Computerspiel kaufen, aber bist dir nicht sicher, welches das Beste ist. Fragst du %s um Rat?\ny/n:", student4.name);
            scanf("%s", awnser);
            if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
                printf("%s empfiehlt dir das Spiel, das er gerade spielt. Du kaufst es und bist begeistert von dem Spiel.", student4.name);
                student4.friendliness += 7;
                student4.happyness += 5;
            } else {
                printf("Du entscheidest dich alleine und kaufst ein anderes Spiel. Später findest du heraus, dass das Spiel, das %s empfohlen hat, viel besser ist.", student4.name);
                student4.friendliness -= 3;
                student4.happyness -= 2;
            }
            break;




    }
    printf("\n\n\n");
    return startDay(completedDays, student1, student2, student3, student4, teacher1, teacher2, daysPassed, name);
}

int main(){
    setlocale(LC_ALL, "de_DE.utf8");
    printf("Willkommen zum Schulsimulator!\nHier wirst du über verschiedene Eingabemöglichkeiten mit deinen Mitschülern und Lehrern Interagieren.\nAuch wenn es anfangs vielleicht nicht so wirkt ist dieses Spiel sehr komplex. Fangen wir aber ersteinmal mit den Grundlagen an: Wie heißt du?\nName: ");
    char name[50];
    scanf("%s", name);
    printf("Sehr gut. In dem Spiel wirst du öfter einfache Ja oder Nein Fragen beantworten müssen. Dazu wird in der Konsole immer 'y/n' für 'yes or no' stehen. Gebe einfach ein y ein, wenn du Ja sagen willst und ein n wenn du nein sagen willst. Jede eingabe, die kein 'y' ist, wird als Nein akzeptiert.\n\nHier ist auch schon deine erste Frage: Möchtest du deine Mitschüler und Lehrer selbst benennen?\ny/n: ");
    int selfnameStudents;
    char awnser[2];
    scanf("%s", awnser);
    struct Student student1 = {18, "m", "", 0, 0, 0, 0};
    struct Student student2 = {21, "w", "", 0, 0, 0, 0};
    struct Student student3 = {19, "w", "", 0, 0, 0, 0};
    struct Student student4 = {20, "m", "", 0, 0, 0, 0};

    struct Teacher teacher1 = {45, "m", "", 0, 0, 0, 0};
    struct Teacher teacher2 = {38, "w", "", 0, 0, 0, 0};

    if(strcmp(awnser, "y") == 0 || strcmp(awnser, "Y") == 0){
        printf("Geht klar! In dem Spiel gibt es insgesammt 5 Mitschüler und 2 Lehrer. Wie soll der erste Mitschüler (männlich, 18 jahre) heißen?\nName: ");

        char nameStudent1[50];
        scanf("%s", nameStudent1);
        strncpy(student1.name, nameStudent1, sizeof(student1.name));
        printf("Der erste Mitschüler heißt %s. Wie soll der zweite Mitschüler (Weiblich, 21 Jahre)  heißen?\nName: ", student1.name);

        char nameStudent2[50];
        scanf("%s", nameStudent2);
        strncpy(student2.name, nameStudent2, sizeof(student2.name));
        printf("Der zweite Mitschüler heißt %s. Wie soll der dritte Mitschüler (Weiblich, 19 Jahre) heißen?\nName: ", student2.name);

        char nameStudent3[50];
        scanf("%s", nameStudent3);
        strncpy(student3.name, nameStudent3, sizeof(student3.name));
        printf("Der dritte Mitschüler heißt %s. Wie soll der vierte Mitschüler (Männlich, 20 Jahre) heißen?\nName: ", student3.name);

        char nameStudent4[50];
        scanf("%s", nameStudent4);
        strncpy(student4.name, nameStudent4, sizeof(student4.name));

        printf("Sehr gut. Kommen wir nun zu den Lehrern. Wie soll der erste Lehrer (Männlich, 45) heißen?\nName: ");
        char nameTeacher1[50];
        scanf("%s", nameTeacher1);
        strncpy(teacher1.name, nameTeacher1, sizeof(teacher1.name));

        char nameTeacher2[50];
        printf("Der erste Lehrer heißt %s. Wie soll der Zweite Lehrer (Weiblich, 38) Heißen?\nName: ", teacher1.name);
        scanf("%s", nameTeacher2);
        strncpy(teacher2.name, nameTeacher2, sizeof(teacher2.name));

    } else{
        printf("Ok, dann übernehme ich die benennung!");
        char possibleMaleStudentNames[15][50] = {"Max", "David", "Luis", "Henry", "Roy", "Sebastian", "Jonathan", "Peter", "Richard", "Kevin", "Frederick", "Miles", "Alfred", "Robert"};
        char possibleFemaleStudentNames[15][50] = {"Mia", "Anna", "Millie", "Sarah", "Lara", "Georgina", "Alexandra", "Lydia", "Sophoa", "Nicole", "Isabel", "Tia", "Alisha", "Linda"};
        char possibleMaleTeacherNames[7][50] = {"Derek", "Frank", "Dustin", "Gary", "Erik", "Raymond", "Samuel", "Dennis", "Gabriel", "Ronny"};
        char possibleFemaleTeacherNames[7][50] = {"Eva", "Heidi", "Evelyn", "Elise", "Julia", "Rachel", "Gabi", "Vanessa", "Emma", "Karina"};
        srand(time(NULL));

        strncpy(student1.name, possibleMaleStudentNames[(int) rand() % 15], sizeof(student1.name));

        strncpy(student2.name, possibleFemaleStudentNames[(int) rand() % 15], sizeof(student2.name));

        char nameStudent3[50] = "";
        strcpy(nameStudent3, possibleFemaleStudentNames[(int) rand() % 15]);
        while(strcmp(nameStudent3, student2.name) == 0){
            strcpy(nameStudent3, possibleFemaleStudentNames[(int) rand() % 15]);
        }
        strncpy(student3.name, nameStudent3, sizeof(student3.name));

        char nameStudent4[50] = "";
        strcpy(nameStudent4, possibleMaleStudentNames[(int) rand() % 15]);
        while(strcmp(nameStudent4, student1.name) == 0){
            strcpy(nameStudent4, possibleMaleStudentNames[(int) rand() % 15]);
        }
        strncpy(student4.name, nameStudent4, sizeof(student4.name));

        strncpy(teacher1.name, possibleMaleTeacherNames[(int) rand() % 7], sizeof(teacher1.name));

        strncpy(teacher2.name, possibleMaleTeacherNames[(int) rand() % 7], sizeof(teacher2.name));
    }

    printf("Jetzt wo alle schüler benannt sind, können wir direkt los legen.\n\n");

    int *completedDays[65];

    int i;
    for(i = 0; i < 65; i++){
        completedDays[i] = 0;
    }

    startDay(completedDays, student1, student2, student3, student4, teacher1, teacher2, 0, name);

    return 1;


}

