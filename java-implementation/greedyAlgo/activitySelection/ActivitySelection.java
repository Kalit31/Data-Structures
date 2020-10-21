package greedyAlgo.activitySelection;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class ActivitySelection {

    public static void activitySelection(ArrayList<Activity> activityList){

        Comparator<Activity> finishTimeComparator = new Comparator<Activity>() {
            @Override
            public int compare(Activity activity, Activity t1) {
                return activity.getFinishTime()-t1.getFinishTime();
            }
        };
        Collections.sort(activityList,finishTimeComparator);
        Activity previousActivity = activityList.get(0);

        System.out.println("\n\nRecommended Schedule:\n"+activityList.get(0));

        for(int i=1;i<activityList.size();i++){
            if(activityList.get(i).getStartTime() > previousActivity.getFinishTime()){
                System.out.println(activityList.get(i));
                previousActivity = activityList.get(i);
            }
        }
    }
}
