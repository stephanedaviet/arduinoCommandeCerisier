// Définition d'une constante pour le numéro de la broche de commande (sur laquelle
// va par exemple être branchée un relais).
const int BROCHE_SORTIE_COMMANDE = 12;

// Temps minimum d'activation de la commande de sortie (en secondes, cf. utilisation dans loop()).
const int TEMPS_ACTIVATION_MIN = 20;
// Temps maximum d'activation.
const int TEMPS_ACTIVATION_MAX = 60;

// Temps minimum d'activité entre 2 activations (en secondes).
const int TEMPS_INACTIVITE_MINIMUM = 3.5*60;
// Temps maximum d'inactivité.
const int TEMPS_INACTIVITE_MAXIMUM = 6.5*60;


// Méthode d'intialisation exécutée une seule fois au démarrage de l'Arduino
void setup()
{
	// Paramètrage de la broche dont le numéro a été défini dans la constante
	// BROCHE_SORTIE_COMMANDE en tant que sortie (pour pouvoir y écrire
	// des valeurs (i.e. y envoyer un signal)).
	pinMode(BROCHE_SORTIE_COMMANDE, OUTPUT);
}

// Méthode exécutée en boucle une fois l'Arduino démarré et la méthode setup() exécutée
void loop()
{
	// Écriture de la valeur HIGH sur la broche BROCHE_SORTIE_COMMANDE (i.e.
	// activation de la commande via l'envoi d'un signal sur la broche).
	digitalWrite(BROCHE_SORTIE_COMMANDE, HIGH);
	// Attente pendant un temps aléatoire compris entre TEMPS_ACTIVATION_MIN et
	// TEMPS_ACTIVATION_MAX. Pendant ce temps, BROCHE_SORTIE_COMMANDE reste à la dernière
	// valeur qui lui a été écrite (HIGH dans ce cas, i.e. état activé).
	// Il s'agit donc de déterminer ici la durée de la période d'activation.
	delay(random(TEMPS_ACTIVATION_MIN, TEMPS_ACTIVATION_MAX)*1000);
	
	// Écriture de la valeur LOW (i.e. désactivation de la commande).
	digitalWrite(BROCHE_SORTIE_COMMANDE, LOW);
	// Attente pendant un temps aléatoire compris entre TEMPS_INACTIVITE_MINIMUM et
	// TEMPS_INACTIVITE_MAXIMUM. Pendant ce temps, BROCHE_SORTIE_COMMANDE reste à la dernière
	// valeur qui lui a été écrite (HIGH dans ce cas, i.e. état activé).
	// Il s'agit donc de déterminer ici la durée de la période d'inactivité.
	delay(random(TEMPS_INACTIVITE_MINIMUM, TEMPS_INACTIVITE_MAXIMUM)*1000);
}

