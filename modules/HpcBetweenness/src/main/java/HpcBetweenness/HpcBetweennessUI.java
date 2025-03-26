package HpcBetweenness;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author reecedevenney
 */
import HpcBetweenness.HpcBetweenness;
import javax.swing.JPanel;
import org.gephi.statistics.spi.Statistics;
import org.gephi.statistics.spi.StatisticsUI;
import org.openide.util.lookup.ServiceProvider;

/**
 *
 * @author reecedevenney
 */
@ServiceProvider(service = StatisticsUI.class)
public class HpcBetweennessUI implements StatisticsUI {

    private HpcBetweenness statistic;

    @Override
    public JPanel getSettingsPanel() {
        return null;
    }

    @Override
    public void setup(Statistics ststcs) {
        this.statistic = (HpcBetweenness) ststcs;
    }

    @Override
    public void unsetup() {
        this.statistic = null;
    }

    @Override
    public Class<? extends Statistics> getStatisticsClass() {
        return HpcBetweenness.class;
    }

    @Override
    public String getValue() {
        if (statistic != null) {
            return "" + statistic.getIndexArray();
        }
        return "";
    }

    @Override
    public String getDisplayName() {
        return "HpcBetweenness";
    }

    @Override
    public String getCategory() {
        return StatisticsUI.CATEGORY_NETWORK_OVERVIEW;
    }

    @Override
    public int getPosition() {
        return 10000;
    }

    @Override
    public String getShortDescription() {
        return null;
    }
}

