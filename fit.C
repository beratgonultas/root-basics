void fit() 
{
	TH1F *hist1 = new TH1F ("hist1", "Histogram", 100, 1, 10);

	TRandom2 *rand = new TRandom2(3);

	fstream file;
	file.open("data_gaus.txt", ios::out);
	
	for(int i=0; i<1000; i++)
	{
		double r = rand->Gaus(5, 1);
		file << r << endl;
	}

	file.close();
	
	file.open("data_gaus.txt", ios::in);
	
	double value;

	while(1)
	{
		file >> value;
		hist1->Fill(value);
		if(file.eof()) break;
	}

	file.close();

	hist1->GetXaxis()->SetTitle("X Axis");
	hist1->GetYaxis()->SetTitle("Y Axis");

	TF1 *fit = new TF1("fit", "gaus", 4, 6);

	

	TCanvas *c1 = new TCanvas ();
	hist1->Draw();
	hist1->Fit("fit", "R");
	//or just
	//hist1->Fit("gauss");
}
