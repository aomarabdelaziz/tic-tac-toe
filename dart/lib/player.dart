class Player 
{
  
  String? pOperator;
  String? _name;

  Player();

  Player.fromPlayer(this.pOperator   , this._name);

  String? get getOperator =>  pOperator   ;

  set setOperator(String? value)  => pOperator = value;

  String? get getName => _name;
  
  set setName(String? value)  => _name = value;



}