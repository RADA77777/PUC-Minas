import 'package:flutter/material.dart';
import 'package:listacontatos/models/contato.dart';
import 'package:listacontatos/providers/auth_provider.dart';
import 'package:listacontatos/providers/contatosprovider.dart';
import 'package:listacontatos/screens/contact_finder.dart';
import 'package:listacontatos/screens/contact_info.dart';
import 'package:listacontatos/screens/list_birth_dates.dart';
import 'package:provider/provider.dart';
import 'add_bills.dart';

class Homepage extends StatefulWidget {
  static const routename = 'homepage';
  @override
  _HomepageState createState() => _HomepageState();
}

class _HomepageState extends State<Homepage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        // Trocar o Icon
        actions: [
          IconButton(
              icon: Icon(Icons.person_search),
              onPressed: () {
                showSearch(context: context, delegate: ContactFinder());
              })
        ],
        title: Text('Contatos'),
        centerTitle: true,
      ),
      drawer: Drawer(
        child: ListView(
          padding: EdgeInsets.zero,
          children: [
            Container(
              child: DrawerHeader(
                child: Text(
                  'Contatos',
                  style: TextStyle(fontSize: 35, fontWeight: FontWeight.bold),
                ),
                decoration:
                    BoxDecoration(color: Theme.of(context).primaryColor),
              ),
            ),
            ListTile(
              title: Text('Sair'),
              onTap: () async {
                await Provider.of<AuthProvider>(context, listen: false)
                    .sign_out();
              },
              leading: Icon(
                Icons.exit_to_app,
                color: Colors.red,
              ),
            ),
            ListTile(
              title: Text('Ver aniversários'),
              onTap: () => Navigator.of(context).pushNamed(ListOfBirthdates.routename),
              leading: Icon(
                Icons.calendar_today,
                color: Colors.red,
              ),
            )
          ],
        ),
      ),
      floatingActionButtonLocation: FloatingActionButtonLocation.centerFloat,
      floatingActionButton: FloatingActionButton(
          child: Icon(Icons.add),
          onPressed: () => Navigator.of(context)
              .push(MaterialPageRoute<void>(builder: (context) => Bills()))),
      body: FutureBuilder(
        future:
            Provider.of<ContatosProvider>(context, listen: false).fetch_data(),
        builder: (ctx, result) =>
            result.connectionState == ConnectionState.waiting
                ? Center(child: CircularProgressIndicator())
                : SingleChildScrollView(
                    child: Consumer<ContatosProvider>(
                        builder: (context, contas, _) => ListView.builder(
                            scrollDirection: Axis.vertical,
                            shrinkWrap: true,
                            itemCount: contas.all_inserted.length,
                            itemBuilder: (ctx, index) =>
                                ContaCard(conta: contas.all_inserted[index])))),
      ),
    );
  }
}

class ContaCard extends StatelessWidget {
  final Contato conta;
  const ContaCard({Key key, this.conta}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    CircleAvatar avatar = conta.img_path == 'none'
        ? CircleAvatar(
            radius: 25,
            child: FittedBox(
              fit: BoxFit.fill,
              child: Text(conta.name[0]),
            ),
          )
        : CircleAvatar(
            radius: 25,
            backgroundImage: NetworkImage(conta.img_path),
          );

    return Card(
      elevation: 8,
      child: ListTile(
        trailing: GestureDetector(
          child: Icon(Icons.delete, color: Colors.red),
          onTap: () async {
            await Provider.of<ContatosProvider>(context, listen: false)
                .remove(conta.id);
          },
        ),
        onTap: () {
          Navigator.of(context)
              .pushNamed(ContactInfo.routename, arguments: conta.id);
        },
        leading: avatar,
        title: Text(conta.name),
        subtitle: Text(conta.phone),
      ),
    );
  }
}
