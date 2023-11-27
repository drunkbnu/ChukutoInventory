#include <string>
#include <vector>

using std::string;
using std::vector;

class Bien {
    public:
        string nro();
        string dpto();
        string marca();
        string modelo();
        string texto();
        string fechaIncorp();
        string fechaModif();
        string fechaDesinc();
        vector<string> _vector();
        void nro(string valor);
        void dpto(string valor);
        void marca(string valor);
        void modelo(string valor);

        Bien(string &nro, string &dpto, string &marca, string &modelo);
        Bien(string &texto);
    private:
        string _nro;
        string _dpto;
        string _marca;
        string _modelo;
        string fecha_incorp;
        string fecha_modif;
        string fecha_desinc;
        void actualizarFechaModif();
        string fechaLegible(string& fecha);
};