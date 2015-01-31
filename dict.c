#include<gtk/gtk.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
 
GtkWidget *window;
GtkWidget *table;
GtkWidget *button1;
GtkWidget *button2;
GtkWidget *entry1;
GtkWidget *entry2;


int search_word(char *word, char *dic[], int n)
{
 int low = 0, high = n - 1, mid, searchpos, wordlen = strlen(word);
 do
 {
 mid = (low + high)/2;
 searchpos = strncasecmp(word, dic[mid], wordlen);
 if(searchpos == 0)
 return mid;
 else if(searchpos < 0)
  high = mid - 1;
 else
 low = mid + 1;
 } while(high > low);
}

void query()
{
 gtk_rc_add_default_file("./gtkrc.zh_CN");
 int search_word(char *word, char *dic[], int n);
 char nm[100];
 strcpy(nm, gtk_entry_get_text(GTK_ENTRY(entry1)));
 char *nam;
 nam = nm;
 char dicti[4][100] = {{"Know:v.知道、了解、认识"},
                     {"Knowledge:n.知识、学问、认识"},
                     {"Knowledgeable:a.聪明的、有知识的"},
                     {"Known:a.已知的、有名的;vbl.知道"} };
 char *dict[4];
 dict[0] = &dicti[0][0];
 dict[1] = &dicti[1][0];
 dict[2] = &dicti[2][0];
 dict[3] = &dicti[3][0];
 int k;
 k = search_word(nam, dict, 4);
 char name[100] ;
 name[0] = dicti[k][0];
 gtk_entry_set_text (GTK_ENTRY(entry2), name);
}

void clear()
{
 gtk_entry_set_text(GTK_ENTRY(entry2),"");
}

int main(int argc, char *argv[])
{
 gtk_init(&argc, &argv);
 window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
 gtk_window_set_title (GTK_WINDOW (window),
                       g_locale_to_utf8("我的电子词典", -1, NULL, NULL, NULL));
 table = gtk_table_new(3,5,FALSE);
 button1 = gtk_button_new_with_label (g_locale_to_utf8("查询",-1,NULL,NULL,NULL));
 button2 = gtk_button_new_with_label (g_locale_to_utf8("结果",-1,NULL,NULL,NULL));
 entry1 = gtk_entry_new ();
 entry2 = gtk_entry_new ();
 
 gtk_container_add (GTK_CONTAINER (window), table);
 gtk_table_attach (GTK_TABLE(table), entry1, 0, 4, 0, 1,
               (GtkAttachOptions) (0), (GtkAttachOptions) (0), 10, 10);
 gtk_table_attach (GTK_TABLE(table), button1, 4, 5, 0, 1,
               (GtkAttachOptions) (0), (GtkAttachOptions) (0), 10, 10);
 gtk_table_attach (GTK_TABLE(table), entry2, 0, 4, 1, 3,
              (GtkAttachOptions) (0), (GtkAttachOptions) (0),  0, 10);
 gtk_table_attach (GTK_TABLE(table), button2, 4, 5, 1, 3,
              (GtkAttachOptions) (0), (GtkAttachOptions) (0), 0, 10);
 g_signal_connect (G_OBJECT (button1), "clicked", G_CALLBACK (query), NULL);
 g_signal_connect (G_OBJECT (button2), "clicked", G_CALLBACK (clear), NULL);
 gtk_widget_show_all (window);
 gtk_main ();

 return 0;
}
